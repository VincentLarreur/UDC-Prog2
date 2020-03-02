/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

tList createEmptyList() {
    tList* result = malloc(sizeof(tList));
    result->data=malloc(sizeof(tItemL));
    result->data->numVotes=NULL;
    strcpy(result->data->partyName,"");
    result->pos=-1;
    result->NextItem=NULL;
    return *result;
}

int isEmptyList (tList l) {
    return(l.pos==-1 && l.NextItem==NULL);
}

tPosL first (tList l) {
    return l.pos;
} 

tPosL next (tPosL p, tList l) {
    tList result=l;
    while (!isEmptyList(result))
    {
        if (result.pos==p) {
            return result.NextItem->pos;
        }
        else result=*(result.NextItem);
    }
    return LNULL;
}

tPosL previous (tPosL p, tList l) {
    tList result=l;
    while (!isEmptyList(*(result.NextItem)))
    {
        if (result.NextItem->pos==p) {
            return result.pos;
        }
        else result=*(result.NextItem);
    }
    return LNULL;
    
}

tTuple insertItem (tItemL i, tPosL p, tList l) {
    tList* add=malloc(sizeof(tList));
    tList* current = &l;
    int bool=0;
    if (!isEmptyList(l)) {
        add->data=&i;
        while (!isEmptyList(*(current->NextItem)))
        {
            if (current->NextItem->pos==p) {
                add->pos=current->pos+1;
                add->NextItem=current->NextItem;
                current->NextItem=add;
                current=current->NextItem->NextItem;
                while(!isEmptyList(*current)) {
                    current->pos++;
                    current=current->NextItem;
                }
                bool=1;
            }
            else current=current->NextItem;
        }
        if (p==LNULL) {
            add->pos=current->pos+1;
            *(add->NextItem)=createEmptyList();
            current->NextItem=add;
            bool=1;
        }
    }
    else {
        if (isEmptyList(*current)) {
            current->pos=0;
            *(current->NextItem)=createEmptyList();
            current->data=&i;
            bool=1;
            }
    }
    tTuple *result = malloc(sizeof(tTuple));
    result->list=l;
    result->b=bool;
    return *result;
}

tList deleteAtPosition (tPosL p, tList l) {
    tList* current = &l;
    tList* result=&l;
    if(!isEmptyList(l)) {
        if (current->pos==p) {
            tList* memo=current->NextItem;
            free(current->data);
            free(current);
            result=memo;
            while (!(isEmptyList(*memo)))
            {
                memo->pos--;
                memo=memo->NextItem;
            }
            
        }
        else {
            while (!(isEmptyList(*(current->NextItem))))
            {
                if(current->NextItem->pos==p) {
                    if (!isEmptyList(*(current->NextItem->NextItem))) {
                        tList* save=current->NextItem->NextItem;
                        tList* todelete=current->NextItem;
                        current->NextItem=save;
                        free(todelete->data);
                        free(todelete);
                        current=current->NextItem;
                        while (!isEmptyList(*current))
                        {
                            current->pos--;
                            current=current->NextItem;
                        }
                    }
                    else {
                        tList* td=current->NextItem;
                        current->NextItem=NULL;
                        free(td->data);
                        free(td);
                    }
                }
                else current=current->NextItem;
            }
        }
    }
    return *result;
}

tItemL getItem (tPosL p, tList l) {
    tList search = l;
    while (!isEmptyList(search))
    {
        if (search.pos==p) {
            return *(search.data);
        }
        else search=*(search.NextItem);
    }
    
}

tList updateVotes (tNumVotes v, tPosL p, tList l) {
    tList search = l;
    tList* result = &search;
    while (!isEmptyList(search))
    {
        if (search.pos==p) {
            search.data->numVotes=v;
        }
        else search=*(search.NextItem);
    }
    return *result;
}

tPosL findItem (tPartyName pn, tList l) {
    tList search = l;
    while (!isEmptyList(search))
    {
        if (strcmp(search.data->partyName,pn)) {
            return search.pos;
        }
        else search=*(search.NextItem);
    }
    return LNULL;
}



/* Write your code here... */
/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */
#include "dynamic_list.h"

void createEmptyList(tList* l) {
    l->firstElem=LNULL;
}

bool isEmptyList (tList l) {
    return(l.firstElem==LNULL);
}

tPosL first (tList l) {
    return l.firstElem;
} 

tPosL last(tList l) {
    if (isEmptyList(l)) return LNULL;
    tPosL current=l.firstElem;
    while(current->next!=NULL) {
        current = current->next;
    }
    return current;
}

tPosL next (tPosL p, tList l) {
    tPosL result=l.firstElem;
    while (result!=LNULL)
    {
        if (result->next==p->next && result->data.partyName==p->data.partyName && result->data.numVotes==p->data.numVotes) {
            return result->next;
        }
        else result=result->next;
    }
    return LNULL;
}

tPosL previous (tPosL p, tList l) {
    tPosL result=l.firstElem;
    while (result->next!=LNULL)
    {
        if (result->next==p) {
            return result;
        }
        else result=result->next;
    }
    return LNULL;
}

bool insertItem (tItemL i, tPosL p, tList* l) {
    if (p==LNULL) {
        tPosL elem=malloc(sizeof(tPosL));
        elem->next=malloc(sizeof(tPosL));
        elem->next=LNULL;
        elem->data.numVotes=i.numVotes;
        strcpy(elem->data.partyName,i.partyName);
        //we've 2 cases when we have to put it at the end of the list
        //first case, list is empty
        if (isEmptyList(*l)) {
            l->firstElem=elem;
            return true;
        }

        tPosL findEnd;
        findEnd=l->firstElem;

        //second case, we find the last elem of the list and we put the new item after it
        while(findEnd->next!=LNULL) {
            findEnd=next(findEnd,*l);
        }
        findEnd->next=elem;
        return true;
    }
    // Now when we have to put the elem just before the valid position p
    else {
        tPosL findElem = l->firstElem;
        //first case : one elem in the list and this elem is p
        if (findElem==p) {
            tPosL elem2=malloc(sizeof(tPosL));
            elem2->data=i;
            elem2->next=l->firstElem;
            l->firstElem=elem2;
            return true;
        }
        //second case, more than one elem in the list, we have to find p and insert the item before
        else {
            while(findElem->next!=p || findElem->next!=LNULL) {
                findElem = findElem->next;
            }
            if (findElem->next==LNULL) return false; //we haven't found p in the list
            tPosL save = findElem->next;
            tPosL add= malloc(sizeof(tPosL));
            add->next=save;
            add->data=i;
            findElem->next=add;
            return true;
        }
    }

}

void deleteAtPosition (tPosL p, tList* l) {
    tPosL save;
    tPosL findElem=l->firstElem;
    //first case, the first elem of the list is p
    if (findElem->data.numVotes==p->data.numVotes && strcmp(findElem->data.partyName,p->data.partyName)==0 && findElem->next==p->next) {
        if (l->firstElem->next!= LNULL) {
            save=l->firstElem;
            l->firstElem=l->firstElem->next;
            free(save);
            return;
        }
        else {
            save=l->firstElem;
            l->firstElem=LNULL;
            free(save);
            return;
        }
    }
    //2nd case, p is not the first elem of the list
    while(findElem->next!=LNULL && findElem->next->data.numVotes!=p->data.numVotes && strcmp(findElem->next->data.partyName,p->next->data.partyName)!=0
          && findElem->next->next!=p->next ) {
        findElem=findElem->next;
    }
    if (findElem->next->next!=LNULL) {
        save=findElem->next;
        findElem->next=findElem->next->next;
        free(save);
        return;
    }
    else {
        save=findElem->next;
        findElem->next=LNULL;
        //free(save);
        return;
    }
    return;
}

tItemL getItem (tPosL p, tList l) {
    tPosL findElem=l.firstElem;
    while(findElem!=LNULL && findElem->data.partyName!=p->data.partyName && findElem->next!=LNULL) {
        findElem=findElem->next;
    }
    if (findElem!=LNULL) return findElem->data;
}

void updateVotes (tNumVotes v, tPosL p, tList* l) {
    tPosL findElem=l->firstElem;
    while(findElem!=p) {
        findElem=findElem->next;
    }
    findElem->data.numVotes=v;
}

tPosL findItem (tPartyName pn, tList l) {
    tPosL findItem=l.firstElem;
    if (isEmptyList(l)) return LNULL;
    findItem->next=l.firstElem->next;
    strcpy(findItem->data.partyName,l.firstElem->data.partyName);
    while(findItem!=LNULL) {
        if (strcmp(findItem->data.partyName,pn)==0) {
        return findItem;
    }
        findItem=findItem->next;
    }
    return findItem;
}
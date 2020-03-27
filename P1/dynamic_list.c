/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1:  LOGIN 1:
 * AUTHOR 2:  LOGIN 2:
 * GROUP: 6.1
 * DATE: 27/03/2020
 */
#include "dynamic_list.h"

/**
 * Creates an empty list
 * @param l : tList*, the list we want to create
 */
void createEmptyList(tList* l) {
    l->firstElem=LNULL;
}

/**
 * Determines whether the list is empty or not
 * @param l : tList, the list we want to determine if it's empty
 * @return : a boolean, true if l is empty, false otherwise
 */
bool isEmptyList (tList l) {
    return(l.firstElem==LNULL);
}

/**
 * Returns the position of the first element of the list
 * @param l : tList, we want to get the position of the first element of the list l
 * @return : tPosL, the position of the first element of the list
 */
tPosL first (tList l) {
    return l.firstElem;
} 

/**
 * Returns the position of the last element of the list
 * @param l : tList, we want to get the position of the last element of the list l
 * @return : tPosL, the position of the last element of the list
 */
tPosL last(tList l) {
    if (isEmptyList(l)) return LNULL;
    tPosL current=l.firstElem;
    while(current->next!=NULL) {
        current = current->next;
    }
    return current;
}

/**
 * Returns the position following the one we indicate (or LNULL if the specified position has no next element).
 * @param p : tPosL, the current position
 * @param l : tList, the list we want to manipulate
 * @return : tPosL, the position following the one we indicate (or LNULL if no next element)
 */
tPosL next (tPosL p, tList l) {
    tPosL result=l.firstElem;
    while (result!=LNULL)
    {
        if (result->next==p->next && result->data.partyName==p->data.partyName && result->data.numVotes==p->data.numVotes) {
            //we're checking if the next element of result is the same next element of p
            return result->next; //then we return the next element of return
        }
        else result=result->next; //else return becomes the next element of current return
    }
    return LNULL;
    //if there is no next element, we return LNULL
}

/**
 * Returns the position preceding the one we indicate (or LNULL if the specified position has no previous element).
 * @param p : tPosL, the current position
 * @param l : tList, the list we want to manipulate
 * @return : tPosL, the position preceding the one we indicate (or LNULL if no previous element)
 */
tPosL previous (tPosL p, tList l) {
    tPosL result=l.firstElem;
    while (result->next!=LNULL)
    {
        if (result->next==p) {
            //if the next element of result is p, then result is the previous element of p
            return result; //therefore, we return result
        }
        else result=result->next;
        //else return becomes the next element of current return
    }
    return LNULL;
    //if there is no previous element, we return LNULL
}

/**
 * Inserts an element containing the provided data item in the list. If the specified position is LNULL, then the element is added at
 * the end of the list; otherwise, it will be placed right before the element currently holding that position. It the element could be
 * inserted, the value true is returned, false otherwise
 * @param i : tItemL, the item we want to insert
 * @param p : tPosL, the position where we want to insert the element (if LNULL: the element is placed at the end of the list)
 * @param l : tList, we want to insert an item in this list l
 * @return : boolean, true if the element could be inserted, false otherwise
 */
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
        //first case : one element in the list and this elem is p
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

/**
 * Deletes the element at the given position from the list
 * @param p : tPosL, position of the element we want to delete
 * @param l : tList, we want to delete an element in this list l
 */
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
        return;
    }
}

/**
 * Retrieves the content of the element at the position we indicate
 * @param p : tPosL, the position of the element we want
 * @param l : tList, we want to get an element from this list l
 * @return tItemL, the content of the element at the position p in l
 */
tItemL getItem (tPosL p, tList l) {
    tPosL findElem=l.firstElem;
    while(findElem!=LNULL && findElem->data.partyName!=p->data.partyName && findElem->next!=LNULL) {
        findElem=findElem->next;
    }
    return findElem->data;
}

/**
 * Modifies the number of votes of the element at the position we indicate
 * @param v : tNumVotes, the new number of votes we want to update
 * @param p : tPosL, the position of the element we want to update
 * @param l : tList*, list containing the element we will update
 */
void updateVotes (tNumVotes v, tPosL p, tList* l) {
    tPosL findElem=l->firstElem;
    while(findElem!=p) {
        findElem=findElem->next;
    }
    findElem->data.numVotes=v;
}

/**
 * Returns the position of the first element in the list whose party name is the one indicated (or LNULL if there is no such item)
 * @param pn : tPartyName, the party name we want to find
 * @param l : tList, we search in this list l
 * @return : tPosL, the position of the first element in the list l whose party name is pn
 */
tPosL findItem (tPartyName pn, tList l) {
    tPosL findItem=l.firstElem;
    if (isEmptyList(l)) return LNULL;
    findItem->next=l.firstElem->next;
    strcpy(findItem->data.partyName,l.firstElem->data.partyName);
    while(findItem!=LNULL) {
        if (strcmp(findItem->data.partyName,pn)==0) {
            // we're comparing
        return findItem;
    }
        findItem=findItem->next;
    }
    return findItem;
}
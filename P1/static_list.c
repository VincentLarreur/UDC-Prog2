/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1:  LOGIN 1:
 * AUTHOR 2:  LOGIN 2:
 * GROUP: 6.1
 * DATE: 27/03/2020
 */

#include "static_list.h"

/**
 * Creates an empty list
 * @param l : tList*, the list we want to create
 */
void createEmptyList(tList * l){
    for(int i=0;i<NB;i++) {
        (*l)[i].numVotes=-1;
    }
}

/**
 * Determines whether the list is empty or not
 * @param l : tList, the list we want to determine if it's empty
 * @return : a boolean, true if l is empty, false otherwise
 */
bool isEmptyList (tList l){
    if(l[first(l)].numVotes==-1)
    {
        return true;
    } else {
        return false;
    }
}

/**
 * Returns the position of the first element of the list
 * @param l : tList, we want to get the position of the first element of the list l
 * @return : tPosL, the position of the first element of the list
 */
tPosL first (tList l) {
    return 0;
}

/**
 * Returns the position of the last element of the list
 * @param l : tList, we want to get the position of the last element of the list l
 * @return : tPosL, the position of the last element of the list
 */
tPosL last (tList l) {
    int i = 0;
    while(i<NB && l[i].numVotes!=-1)
    {
        i++;
    }
    return i;
}

/**
 * Returns the position following the one we indicate (or LNULL if the specified position has no next element).
 * @param p : tPosL, the current position
 * @param l : tList, the list we want to manipulate
 * @return : tPosL, the position following the one we indicate (or LNULL if no next element)
 */
tPosL next (tPosL pos, tList l){
    if((l[pos+1]).numVotes == -1){
        return LNULL;
    }
    else {
        return pos+1;
    }
}

/**
 * Returns the position preceding the one we indicate (or LNULL if the specified position has no previous element).
 * @param p : tPosL, the current position
 * @param l : tList, the list we want to manipulate
 * @return : tPosL, the position preceding the one we indicate (or LNULL if no previous element)
 */
tPosL previous (tPosL pos, tList l){
    if((l[pos-1]).numVotes == -1){
        return LNULL;
    }
    else{
        return pos-1;
    }
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
bool insertItem (tItemL item, tPosL pos, tList * l){
    if(last(*l) == NB-1) // list is full
    {
        return false;
    }
    tPosL posInsert;
    if (pos==LNULL) {
        // if the pos provided is LNULL
        if (isEmptyList(*l)) {
            // if the list is empty, we insert the item at position 0
            posInsert = 0;
        } else {
            // else we insert the item at the end of the list
            posInsert = last(*l);
        }
    } else
        // If the pos provided is an int except -1
    {
        if((*l)[pos].numVotes == -1)//decalage
        {
            tPosL tmp;
            for(tmp = last(*l); tmp!=pos; tmp--)
            {
                // we shift the element to insert the item at the right position
                *l[tmp+1] = *l[tmp];
            }
        }
        posInsert = pos;
    }
    (*l)[posInsert] = item;
    return true;
}

/**
 * Deletes the element at the given position from the list
 * @param p : tPosL, position of the element we want to delete
 * @param l : tList, we want to delete an element in this list l
 */
void deleteAtPosition (tPosL pos, tList * l){
    int i;
    tPosL poslast = last(*l);
    for(i=pos;i<poslast;i++){
        // we shift the element to delete the item at the position pos
        (*l)[i]=(*l)[i+1];
    }
    (*l)[poslast].numVotes = -1;
}

/**
 * Retrieves the content of the element at the position we indicate
 * @param p : tPosL, the position of the element we want
 * @param l : tList, we want to get an element from this list l
 * @return tItemL, the content of the element at the position p in l
 */
tItemL getItem (tPosL pos, tList l){
    return l[pos];
}

/**
 * Modifies the number of votes of the element at the position we indicate
 * @param v : tNumVotes, the new number of votes we want to update
 * @param p : tPosL, the position of the element we want to update
 * @param l : tList*, list containing the element we will update
 */
void updateVotes (tNumVotes v, tPosL pos, tList * l){
    (*l)[pos].numVotes=v;
}

/**
 * Returns the position of the first element in the list whose party name is the one indicated (or LNULL if there is no such item)
 * @param pn : tPartyName, the party name we want to find
 * @param l : tList, we search in this list l
 * @return : tPosL, the position of the first element in the list l whose party name is pn
 */
tPosL findItem (tPartyName party, tList l){
    for(int i=0;i<NB;i++){
        if (strcmp(l[i].partyName, party)==0){
            return i;
        }
    }
    return LNULL;
}

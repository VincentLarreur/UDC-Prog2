/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"
#include <stdio.h>

<<<<<<< HEAD
void createEmptyList(tList * l){
    for(int i=0;i<NB;i++) {
        (*l)[i].numVotes=-1;
    }
}
// returns tList
// Creates an empty list
// PostCD: The list is initialised and has no elements

bool isEmptyList (tList l){
    if(l[first(l)].numVotes==-1)
    {
        return true;
    } else {
        return false;
    }
}
// Determines whether the list is empty or not.

tPosL first (tList l) {
    return 0;
}
// Returns the position of the first element of the list. PreCD: The list is not empty


tPosL last (tList l) {
    int i = 0;
    while(i<NB && l[i].numVotes!=-1)
    {
        i++;
    }
    return i;
}
// Returns the position of the last element of the list. PreCD: The list is not empty


tPosL next (tPosL pos, tList l){
    if((l[pos+1]).numVotes == -1){
        return LNULL;
    }
    else {
        return pos+1;
    }
}
//→ tPosL  Returns the position following that one we indicate (or LNULL if the specified position has no next element). PreCD: The indicated position is a valid position in the list.

tPosL previous (tPosL pos, tList l){
    if((l[pos-1]).numVotes == -1){
        return LNULL;
    }
    else{
        return pos-1;
    }
}
//Returns the position preceding the one we indicate (or LNULL if the specified position has no previous element). PreCD: The indicated position is a valid position in the list.

bool insertItem (tItemL item, tPosL pos, tList * l){
    if(last(*l) == NB-1) // list is full
    {
        return false;
    }
    tPosL posInsert;
    if (pos==LNULL) {
        if (isEmptyList(*l)) {
            posInsert = 0;
        } else {
            posInsert = last(*l);
        }
    } else
    {
        if((*l)[pos].numVotes == -1)//decalage
        {
            tPosL tmp;
            for(tmp = last(*l); tmp!=pos; tmp--)
            {
                *l[tmp+1] = *l[tmp];
            }
        }
        posInsert = pos;
    }
    (*l)[posInsert] = item;
    return true;
}
//→ tList, bool  Inserts an element containing the provided data item in the list. If the specified position is LNULL,
// then the element is added at the end of the list; otherwise, it will be placed right before the element currently
// holding that position. It the element could be inserted, the value true is returned, false otherwise.
// PreCD: The specified position is a valid position in the list or a LNULL position.
// PostCD: The positions of the elements in the list subsequent to the inserted one may have changed their values.

void deleteAtPosition (tPosL pos, tList * l){
    int i;
    int poslast = last(*l);
    for(i=pos;i<poslast;i++){
        *l[i]=*l[i+1];
    }
    (*l)[poslast].numVotes = -1;
}
//→ tList  Deletes the element at the given position from the list.
//PreCD: The indicated position is a valid position in the list.
// PostCD: The deleted position and the positions of the elements of the list subsequent
// to it may have changed their values.

tItemL getItem (tPosL pos, tList l){
    return l[pos];
}
// → tItemL  Retrieves the content of the element at the position we indicate. PreCD: The indicated position is a valid position in the list.

void updateVotes (tNumVotes v, tPosL pos, tList * l){
    (*l)[pos].numVotes=v;
}
// → tList  Modifies the number of votes of the element at the position we indicate. PreCD: The indicated position is a valid position in the list. PostCD: The order of the elements in the list has not been modified.

tPosL findItem (tPartyName party, tList l){
    for(int i=0;i<NB;i++){
        if (strcmp(l[i].partyName, party)==0){
            return i;
        }
    }
    return LNULL;
}
// → tPosL  Returns the position of the first element in the list whose party name is the one indicated (or LNULL if there is no such item).
=======


void createEmptyList (tList* l){
	l=malloc(sizeof(tList));
	for (int i=0;i<MAX;i++){
	    tItemL * p=&(l->tableau[i]);
        p=LNULL;
	}
}


bool isEmptyList (tList l){
	for(int i=0;i<MAX;i++){
		if(&(l.tableau[i])!=LNULL){
			return false;
		}
	}
	return true;
}


tPosL first (tList l) {
    if(isEmptyList(l)) return LNULL;
    else return 0;
}

tPosL last(tList l){
    if(isEmptyList(l)) return LNULL;
    else{
        int i;
        for(i=0;i<MAX;i++){
            if(&(l.tableau[i])==LNULL) return i-1;
        }
    }
}


tPosL next (tPosL pos, tList l){
	if(&(l.tableau[pos+1])==LNULL){
		return LNULL;
	}
	else {
		return pos+1;
	}
}


tPosL previous (tPosL pos, tList l){
	if(&(l.tableau[pos-1])==LNULL){
		return LNULL;
	}
	else{
		return pos-1;
	}
}   

bool isFullList (tList l){
    int i;
    for(i=0;i<MAX;i++){
        if (&(l.tableau[i])==LNULL) return false;
    }
    return true;
}
bool insertItem (tItemL item, tPosL pos, tList * l){
    if(pos > MAX-1) return false;
    if(isFullList(*l)) return false;
    if (&(l->tableau[MAX-1])==LNULL){
        if (pos==LNULL){
            int i;
            for(i=0;i<25;i++){
                if(&(l->tableau[i])==NULL){
                    l->tableau[i]=item;
                    return true;
                }
            }
        }
        int i;
        for(i=MAX-1;i>pos;i--){
            l[i]=l[i-1];
        }
        l->tableau[pos]=item;
        return true;
    }
}

void deleteAtPosition (tPosL pos, tList * l){
	int i;
	free(&(l->tableau[pos]));
	for(i=pos;i<MAX-1;i++){
		l[i]=l[i+1];
	}
}


tItemL getItem (tPosL pos, tList l){
	return l.tableau[pos];
}

void updateVotes (tNumVotes v, tPosL pos, tList * l){
	l->tableau[pos].numVotes=v;
}

tPosL findItem (tPartyName n, tList l){
	for(int i=0;i<MAX;i++){
		if (l.tableau[i].partyName==n){
			return i;
		}
	}
	return LNULL;
}

void deleteList(tList* l){
    free(l);
}
>>>>>>> d28309837cb4c9dd897eecb54ac1d34847ab388a

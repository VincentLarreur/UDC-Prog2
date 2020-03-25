/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"



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
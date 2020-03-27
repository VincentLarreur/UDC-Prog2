/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1:  LOGIN 1:
 * AUTHOR 2:  LOGIN 2:
 * GROUP: 6.1
 * DATE: 27/03/2020
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include "stdlib.h"
#include "types.h"
#include <string.h>
#include <stdbool.h>


#define LNULL NULL

typedef struct tNode* tPosL;
struct tNode {
    tItemL data;
    tPosL next;
};
typedef struct list {
    tPosL firstElem;
} tList;


void createEmptyList(tList* l);

bool isEmptyList (tList l);

tPosL first (tList l) ;

tPosL last (tList l) ;

tPosL next (tPosL p, tList l) ;

tPosL previous (tPosL p, tList l)  ; 

bool insertItem (tItemL i, tPosL p, tList* l) ;

void deleteAtPosition (tPosL p, tList* l) ;

tItemL getItem (tPosL p, tList l);

void updateVotes (tNumVotes v, tPosL p, tList* l);

tPosL findItem (tPartyName pn, tList l);


#endif

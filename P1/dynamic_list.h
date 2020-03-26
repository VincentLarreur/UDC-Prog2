/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
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
// returns tList
// Creates an empty list
// PostCD: The list is initialised and has no elements

bool isEmptyList (tList l);
// Determines whether the list is empty or not. 

tPosL first (tList l) ;
// Returns the position of the first element of the list. PreCD: The list is not empty

tPosL last (tList l) ;
// Returns the position of the last element of the list. PreCD: The list is not empty

tPosL next (tPosL p, tList l) ;
//→ tPosL  Returns the position following that one we indicate (or LNULL if the specified position has no next element). PreCD: The indicated position is a valid position in the list. 

tPosL previous (tPosL p, tList l)  ; 
//Returns the position preceding the one we indicate (or LNULL if the specified position has no previous element). PreCD: The indicated position is a valid position in the list. 
 
bool insertItem (tItemL i, tPosL p, tList* l) ;
//→ tList, bool  Inserts an element containing the provided data item in the list. If the specified position is LNULL, then the element is added at the end of the list; otherwise, it will be placed right before the element currently holding that position. It the element could be inserted, the value true is returned, false otherwise.  PreCD: The specified position is a valid position in the list or a LNULL position. PostCD: The positions of the elements in the list subsequent to the inserted one may have changed their values. 
 
void deleteAtPosition (tPosL p, tList* l) ;
//→ tList  Deletes the element at the given position from the list. 
//PreCD: The indicated position is a valid position in the list. PostCD: The deleted position and the positions of the elements of the list subsequent to it may have changed their values. 
 
tItemL getItem (tPosL p, tList l);
// → tItemL  Retrieves the content of the element at the position we indicate. PreCD: The indicated position is a valid position in the list. 
 
void updateVotes (tNumVotes v, tPosL p, tList* l);
// → tList  Modifies the number of votes of the element at the position we indicate. PreCD: The indicated position is a valid position in the list. PostCD: The order of the elements in the list has not been modified. 
 
tPosL findItem (tPartyName pn, tList l);
// → tPosL  Returns the position of the first element in the list whose party name is the one indicated (or LNULL if there is no such item).  


#endif

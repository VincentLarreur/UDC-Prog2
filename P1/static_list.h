/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: COSSEC--KERLOC'H Perig LOGIN 1: **********
 * AUTHOR 2: LE RHUN Maugan LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include <stdbool.h>
#include <stdlib.h>
/*
typedef int tPosL;

typedef struct {
	tItemL tableau[25];
	tPosL pos;
} tList;
*/
#define LNULL NULL
#define MAX 25

typedef int tPosL;

typedef struct tList {
    tItemL tableau[MAX];
    tPosL pos;
} tList;


void createEmptyList (tList* l);
bool isEmptyList(tList l);
tPosL first(tList l);
tPosL last(tList l);
tPosL next(tPosL pos, tList l);
tPosL previous(tPosL pos, tList l);
bool insertItem(tItemL item, tPosL pos, tList* l);
void deleteAtPosition(tPosL pos, tList* l);
tItemL getItem(tPosL pos, tList l);
void updateVotes(tNumVotes vote, tPosL pos, tList* l);
tPosL findItem(tPartyName n, tList l);
void deleteList(tList* l);

bool copyList(tList l1, tList* l2);






<<<<<<< HEAD
#define LNULL -1
#define NB 25

typedef int tPosL;

typedef tItemL tList[NB];

/* function prototypes */

void createEmptyList (tList*);
bool insertItem(tItemL, tPosL, tList*);
bool copyList(tList, tList*);
void updateVotes(tNumVotes, tPosL, tList*);
void deleteAtPosition(tPosL, tList*);
void deleteList(tList*);
tPosL findItem(tPartyName, tList);
bool isEmptyList(tList);
tItemL getItem(tPosL, tList);
tPosL first(tList);
tPosL last(tList);
tPosL previous(tPosL, tList);
tPosL next(tPosL, tList);
=======
>>>>>>> d28309837cb4c9dd897eecb54ac1d34847ab388a

#endif

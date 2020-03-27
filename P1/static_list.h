/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1:  LOGIN 1:
 * AUTHOR 2:  LOGIN 2:
 * GROUP: 6.1
 * DATE: 27/03/2020
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define LNULL -1
#define NB 25

typedef int tPosL;

typedef tItemL tList[NB];

/* function prototypes */

void createEmptyList (tList*);

bool isEmptyList(tList);

tItemL getItem(tPosL, tList);

tPosL first(tList);

tPosL last(tList);

tPosL next(tPosL, tList);

tPosL previous(tPosL, tList);

bool insertItem(tItemL, tPosL, tList*);

void updateVotes(tNumVotes, tPosL, tList*);

void deleteAtPosition(tPosL, tList*);

tPosL findItem(tPartyName, tList);

#endif

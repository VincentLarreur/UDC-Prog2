/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1:  LOGIN 1:
 * AUTHOR 2:  LOGIN 2:
 * GROUP: 6.1
 * DATE: 27/03/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define CODE_LENGTH 2

#ifdef STATIC_LIST
#include "static_list.h"
#endif
#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef TEST_LIST
#include "list/list.h"
#endif

tList * vote;
tNumVotes nullVotes;

void processCommand(char command_number[CODE_LENGTH+1], char command, char param[NAME_LENGTH_LIMIT+1]) {
    printf("********************\n");
    switch(command) {

        case 'N': ;// case NEW
            printf("%s %c: party %s\n", command_number, command, param);
            bool insertSucess = false;
            if (findItem(param,*vote)==LNULL) {
                // We're checking param doesn't exist in vote
                tItemL i;
                i.numVotes=0;
                strcpy(i.partyName,param);
                insertSucess = insertItem(i,LNULL,vote);
            }
            if(insertSucess)
            {
                // if the item is inserted, we print the message below
                printf("* New: party %s\n",param);
            } else
            {
                // else we print the message below
                printf("+ Error : New not possible\n");
            }
            break;

        case 'V': ; // case VOTE
            printf("%s %c: party %s\n", command_number, command, param);
            tPosL pos=findItem(param,*vote);
            if (pos!=LNULL) { // we're checking that param exist in vote
                tNumVotes nbvote=getItem(pos,*vote).numVotes+1; // we're increasing the number of vote
                updateVotes(nbvote,pos,vote);
                // then we print the update
                printf("* Vote: party %s numvotes %i\n", getItem(pos, *vote).partyName, getItem(pos, *vote).numVotes);
            }
            else
            {
                // else we print there is an error
                printf("+ Error: Vote not possible. Party %s not found. NULLVOTE\n", param);
                nullVotes++;
            }
            break;

        case 'S': ; // case STATS
            printf("%s %c: totalvoters %s\n", command_number, command, param);
            tPosL current = first(*vote);
            tNumVotes totalVote = 0;
            double totalVoters = atoi(param);
            while (current != LNULL)
            {
                tItemL tmp = getItem(current, *vote);
                totalVote+=tmp.numVotes;//we're increasing totalVote with each numVotes of each item
                current = next(current, *vote);
            }
            current=first(*vote);;
            while (current != LNULL) {
                tItemL tmp = getItem(current, *vote);
                if(totalVote == 0)
                {
                    printf("Party %s numvotes %i (0.00%%)\n", tmp.partyName, tmp.numVotes);
                } else
                {
                    printf("Party %s numvotes %i (%.2f%%)\n", tmp.partyName, tmp.numVotes, (tmp.numVotes / (double) totalVote) *100);
                }
                current = next(current, *vote);
            }
            printf("Null votes %d\n", nullVotes);
            totalVote += nullVotes;
            printf("Participation: %i votes from %.0f voters (%.2f%%)\n",totalVote, totalVoters, (totalVote/totalVoters)*100);
            break;

        case 'I': ; // case ILLEGAL
            tPosL post=findItem(param,*vote);
            printf("%s %c: party %s\n", command_number, command, param);
            if (post!=LNULL) { // we're checking param exist in vote
                nullVotes += getItem(post, *vote).numVotes;
                printf("* Illegalize: party %s\n", getItem(post, *vote).partyName);
                deleteAtPosition(post, vote);
                // we delete the item in vote
            }
            else
            {
                printf("+ Error: Illegalize not possible\n");
            }
            break;

        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *df;
    char command_number[CODE_LENGTH+1], command, param[NAME_LENGTH_LIMIT+1];

    df = fopen(filename, "r");
    if (df != NULL) {
        while (!feof(df)) {
            char format[16];
            sprintf(format, "%%%is %%c %%%is", CODE_LENGTH, NAME_LENGTH_LIMIT);
            fscanf(df,format, command_number, &command, param);
            processCommand(command_number, command, param);
        }
        fclose(df);
    } else {
        printf("Cannot open file %s.\n", filename);
    }
}

int main(int nargs, char **args) {

    char *file_name = "new.txt";
    nullVotes = 0;
    vote = (tList*) malloc(sizeof(tList));

    createEmptyList(vote);

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }
    readTasks(file_name);

    free(vote);

    return 0;
}
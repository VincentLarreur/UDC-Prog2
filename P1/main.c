/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define CODE_LENGTH 2

#ifdef STATIC_LIST
#include "static_list.h"
#endif
//#ifdef DYNAMIC_LIST
//#include "dynamic_list.h"
//#endif
//#ifdef TEST_LIST
//#include "list/list.h"
//#endif

tList * vote;
tNumVotes nullVotes;

void processCommand(char command_number[CODE_LENGTH+1], char command, char param[NAME_LENGTH_LIMIT+1]) {
    printf("********************\n");
    switch(command) {
        case 'N': ;
            printf("%s %c: party %s\n", command_number, command, param);
            bool insertSucess = false;
            if (findItem(param,*vote)==LNULL) {
                tItemL i;
                i.numVotes=0;
                strcpy(i.partyName,param);
                insertSucess = insertItem(i,LNULL,vote);
            }
            if(insertSucess)
            {
                printf("* New: party %s\n",param);
            } else
            {
                printf("+ Error : New not possible\n");
            }
            break;
        case 'V': ;
            tPosL pos=findItem(param,*vote);
            if (pos!=LNULL) {
                tNumVotes nbvote=getItem(pos,*vote).numVotes+1;
                updateVotes(nbvote,pos,vote);
                printf("* Vote: party %s⎵numvotes⎵%i", getItem(pos, *vote).partyName, getItem(pos, *vote).numVotes);
            }
            else
            {
                printf("+ Error: Vote not possible. Party %s not found.⎵NULLVOTE\n", param);
                nullVotes++;
            }
            break;
        case 'S': ;
            printf("%s %c: totalvoters %s\n", command_number, command, param);
            tPosL current = first(*vote);
            tNumVotes totalVote = 0;
            double totalVoters = atoi(param);
            while (current != LNULL)
            {
                tItemL tmp = getItem(current, *vote);
                totalVote+=tmp.numVotes;
                current = next(current, *vote);
            }
            current=first(*vote);;
            while (current != LNULL) {
                tItemL tmp = getItem(current, *vote);
                printf("Party %s numvotes %i (%.2f%%)\n", tmp.partyName, tmp.numVotes, tmp.numVotes / totalVoters);
                current = next(current, *vote);
            }
            printf("Null votes %d\n", nullVotes);
            printf("Participation: %i votes from %.0f voters (%.2f%%)\n",totalVote, totalVoters, totalVote/totalVoters);
            break;
        case 'I': ;
            tPosL post=findItem(param,*vote);
            if (post!=LNULL) {
                deleteAtPosition(post, vote);
                printf("* Illegalize: party %s\n", getItem(post, *vote).partyName);
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
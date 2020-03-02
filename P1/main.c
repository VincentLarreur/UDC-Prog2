/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include "types.h"

#define CODE_LENGTH 2

#ifdef STATIC_LIST
#include "static_list.h"
#endif
//#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
//#endif
#ifdef TEST_LIST
#include "list/list.h"
#endif

tList vote=createEmptyList();


void processCommand(char command_number[CODE_LENGTH+1], char command, char param[NAME_LENGTH_LIMIT+1]) {

    switch(command) {
        case 'N': {
            printf("Read: %s %c %s.\n", command_number, command, param);
            if (findItem(param,vote)==LNULL) {
                tItemL i;
                i.numVotes=0;
                strcpy(i.partyName,param);
                insertItem(i,LNULL,vote);
                printf("Insertion successed");
            }
            else
            {
                printf("Party already exists");
            }
        }

        case 'V':{
            printf("Vote: %s %c %s.\n", command_number, command, param);
            tPosL pos=findItem(param,vote);
            if (pos!=LNULL) {
                tNumVotes nbvote=getItem(pos,vote).numVotes+1;
                updateVotes(nbvote,pos,vote);
                printf("Vote successed");
            }
            else
            {
                printf("Error during the vote");
            }
        }

        case 'S':{
            tList* current=&vote;
            tNumVotes totalVote=0;
            if (isEmptyList(*current))
            {
                printf("There is no party right now, statistics impossible");
            }
            
            while (!isEmptyList(*current))
            {
                totalVote+=current->data->numVotes;
            }
            current=&vote;
            printf("Number total of votes: %d",totalVote);
            while (!isEmptyList(*current))
            {
                printf("The party: %s obtained %d percent of votes", current->data->partyName, current->data->numVotes/totalVote);
            }
        }
        
        default: {
            break;
        }
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

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}



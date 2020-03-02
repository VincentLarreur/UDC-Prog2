#include <stdio.h>
#include "types.h"

#define CODE_LENGTH 2

#ifdef STATIC_LIST
#include "static_list.h"
#endif
//#ifdef DYNAMIC_LIST
#include "dynamic_list.c"
//#endif
#ifdef TEST_LIST
#include "list/list.h"
#endif
#include <string.h>


int main(int nargs, char **args) {
    tList t = createEmptyList();
    printf("successed");
    tItemL* it=malloc(sizeof(tItemL));
    strcpy(it->partyName,"salut");
    it->numVotes=0;
    insertItem(*it,LNULL,t);
    printf("the position is %d",findItem("salut",t));
    free(t);
    return 0;
}
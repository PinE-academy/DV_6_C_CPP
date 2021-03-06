#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pattern.h"
#include "linklist.h"

struct Node *pattern_match(const char *filename, const char *word)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("error in loading database file");
        exit(0);
    }
    struct Node *matchList = NULL;// define head of linklist as null...
    char *line=NULL;
    size_t size =0;
    while (!feof(file))
    {
        // read a line
        getline(&line,&size,file);
        if (strstr(line,word))
        { 
             insertEnd(&matchList,line);// add to linklist
        }
        else{
            free(line);
        }
    }
    fclose(file);
    return matchList;
}


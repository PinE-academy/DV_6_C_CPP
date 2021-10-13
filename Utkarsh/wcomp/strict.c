#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strict.h"
#include "linklist.h"

struct Node *strict_match(char *filename, char *word)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("error in loading database file");
        exit(0);
    }
    struct Node *matchList = NULL;// initalize for every call of function
    char *line=NULL;
    size_t size=0;
    while (!feof(file))
    {
        char *match = malloc(sizeof(char) * (strlen(word) + 1));
        fgets(match, strlen(word) + 1, file);
        fseek(file, -strlen(match), SEEK_CUR);

        //read the unitl new line character
        getline(&line,&size,file);

        if (!strcmp(match, word))
        {   
            insertEnd(&matchList,line); //add to the linkedlist
        }
        else{
            free(line);
        }
        free(match);
    }

    fclose(file);
    return matchList;
}


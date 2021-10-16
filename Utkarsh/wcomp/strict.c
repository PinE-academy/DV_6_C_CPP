#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strict.h"
#include "linklist.h"

struct Node *strict_match(const char *filename, const char *word)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("error in loading database file");
        exit(0);
    }
    struct Node *matchList = NULL; // initalize for every call of function
    char *line = NULL;
    size_t size = 0;
    while (!feof(file))
    {
        //read the unitl new line character
        getline(&line, &size, file);
        if ((strncmp(line, word,strlen(word)))==0)
        {
            insertEnd(&matchList, line); //add to the linkedlist
        }
        else
        {
            free(line);
        }
    }

    fclose(file);
    return matchList;
}

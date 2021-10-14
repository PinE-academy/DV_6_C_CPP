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
    struct Node *matchList = NULL; // initalize for every call of function
    char *line = NULL;
    size_t size = 0;
    while (!feof(file))
    {
        //read the unitl new line character
        getline(&line, &size, file);
        // allocate memory for begining word of line
        char *match = malloc(sizeof(char) * (strlen(word) + 1));
        strncpy(match, line, strlen(word));
        if (!strcmp(match, word))
        {
            insertEnd(&matchList, line); //add to the linkedlist
        }
        else
        {
            free(line);
        }
        free(match);
    }

    fclose(file);
    return matchList;
}

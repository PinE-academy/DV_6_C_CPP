#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fuzzy.h"
#include "linklist.h"

struct Node *fuzzy_match(const char *filename, const char *word)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("error in loading database file");
        exit(0);
    }
    struct Node *matchList = NULL; // define head of linklist as null...
    char *line = NULL;
    size_t size = 0;
    while (!feof(file))
    {
        // read a line
        getline(&line, &size, file);
        int match = 0; // to know the all character match
        char *linecopy = line;
        // found match for every character of the word
        while (*linecopy != '\0')
        {
            if (*word == *linecopy)
            {
                word++;
            }
            if (*word == '\0')
            {
                match = 1;
                break;
            }
            linecopy++;
        }

        if (match == 1)
        {
            insertEnd(&matchList, line); // add to linklist
        }
        else
        {
            free(line);
        }
    }
    fclose(file);
    return matchList;
}
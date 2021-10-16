#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fuzzy.h"
#include "linklist.h"

struct Node *fuzzy_match(char *filename, char *word)
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
    int word_size = strlen(word);
    while (!feof(file))
    {
        // read a line
        getline(&line, &size, file);
        int i = 0;
        char *linecopy = line;
        // found match for every character of the word
        while (word_size != 0)
        {
            //convert char to string
            char w[2] = {"\0"};
            w[0] = *(word + i);
            char *ptr = substring(linecopy, w);
            if (ptr == NULL)
            {
                break;
            }
            else
            {
                word_size--;
                i++;
            }
            linecopy = ptr;
        }

        if (word_size == 0)
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

char *substring(char *str1, char *str2)
{
    while (1)
    {
        if (*str1 == '\0')
        {
            return NULL;
        }
        if (*str1 == *str2)
        {
            return str1;
        }
        str1++;
    }
}
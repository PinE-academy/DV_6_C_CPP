#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"strict.h"
#define MAX_SIZE 128
#define no_of_line 30

 char **strict_match(char *filename,char *word)
{
    FILE *file;
    int i = 0;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("error in loading database file");
        exit(0);
    }
    char **match_strings = malloc(sizeof(char *) * no_of_line);
    while (!feof(file))
    {
        char *match = malloc(sizeof(char) * (strlen(word) + 1));
        char *line = malloc(sizeof(char) * MAX_SIZE);
        fgets(match, strlen(word) + 1, file);
        fseek(file, -strlen(match), SEEK_CUR);
        fgets(line, MAX_SIZE, file);
        if (!strcmp(match, word))
        {
            match_strings[i] = line;
            i++;
            if(i==no_of_line){
                free(match);
                free(line);
                break;
            }
        }
        else{
        free(line);
        }
        free(match);
    }
    if(i==0){
        return NULL;
    }
    else{
    return match_strings;
    }
}
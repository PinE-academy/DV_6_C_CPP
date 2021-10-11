#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pattern.h"
#include "strict.h"

char **pattern_match(char *filename, char *word)
{
    FILE *file;
    int i = 0;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("error in loading database file");
        exit(0);
    }
    // total line in file
    int no_of_line = countLine(filename);
    char **match_strings = malloc(sizeof(char *)*no_of_line);
    while (!feof(file))
    {

        //buffer size will be no of character in that line
        int characters = countCharacter(file);
        // allocating memory to buffer
        char *line = malloc(sizeof(char) * (characters + 1));
        fseek(file, -characters, SEEK_CUR); //set pointer to starting of line
        fgets(line, characters + 1, file);
        if (strstr(line,word))
        { 
            match_strings[i] = line;
            i++;
            if (i == no_of_line)
            {
                free(line);
                break;
            }
        }
    }
    fclose(file);
    if (i == 0)
    {
        return NULL;
    }
    else
    {
        return match_strings;
    }
}


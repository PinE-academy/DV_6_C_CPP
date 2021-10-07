#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strict.h"

char **strict_match(char *filename, char *word)
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
    char **match_strings = malloc(sizeof(char *) * no_of_line);
    while (!feof(file))
    {
        char *match = malloc(sizeof(char) * (strlen(word) + 1));
        fgets(match, strlen(word) + 1, file);
        fseek(file, -strlen(match), SEEK_CUR);

        //buffer size will be no of character in that line
        int characters = countCharacter(file);

        if (!strcmp(match, word))
        {
            // allocating memory to buffer
            char *line = malloc(sizeof(char) * (characters + 1));
            fseek(file, -characters, SEEK_CUR); //set pointer to starting of line
            fgets(line, characters + 1, file);
            match_strings[i] = line;
            i++;
            if (i == no_of_line)
            {
                free(match);
                free(line);
                break;
            }
        }
        free(match);
    }
    if (i == 0)
    {
        return NULL;
    }
    else
    {
        return match_strings;
    }
}

// get characters in line
int countCharacter(FILE *file)
{
    char ch;
    int characters = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;
        /* Check new line */
        if (ch == '\n' || ch == '\0')
            break;
    }
    return characters;
}

// get no of line
int countLine(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("error !");
        exit(0);
    }
    int linecount = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        /* Check new line */
        if (ch == '\n' || ch == '\0')
            linecount++;
    }
    //last line count
    linecount++;
    fclose(file);
    return linecount;
}
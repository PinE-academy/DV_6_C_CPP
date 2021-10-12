#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strict.h"

struct Node
{
    char *data;
    struct Node *next;
};
struct Node *head = NULL;
int insertEnd(char *data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // link at end
        temp->next = node;
    }

    return 0;
}
char *strict_match(char *filename, char *word)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("error in loading database file");
        exit(0);
    }
    head = NULL; // initalize for every call of function
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
            insertEnd(line); //add to the linkedlist
        }
        free(match);
    }

    fclose(file);
    return head;
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
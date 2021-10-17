#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strict.h"


void strict_search(char *filename, char *str)
{
    
    FILE *fptr1;
    fptr1 = fopen(filename,"w");
    char s[10],c;
    int len = strlen(str);
    int i = 0;
    int d;
    int seek = fseek(fptr1, 0, 0);
    c = fgetc(fptr1);
    while (c != EOF)
    {
        if (c == ' ' || c == '\n')
        {
            s[i] = '\0';
            i = 0;
            if (strcmp(s, str) == 0)
            {
                while (c = fgetc(fptr1) != '\n')
                {
                    fseek(fptr1, -2L, 1);
                    d = ftell(fptr1);
                }
                while ((c = fgetc(fptr1)) != '\n')
                {
                    fputc(c, fptr1);
                }
            }
        }
        else
        {
            s[i] = c;
            i++;
        }
        c = fgetc(fptr1);
    }
fclose(fptr1);
}

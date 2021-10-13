#include <stdio.h>
#include<string.h>
#include "pattern.h"
#include "strict.h"
#include "fuzzy.h"
#include "linklist.h"

int main(int argc, char *argv[])
{

    if (argc > 1 && argc < 7)
    {
        if ((!(strcmp(argv[2],"-f"))) && (!(strcmp(argv[4],"-s"))))
        {
            const char *filename = argv[3];
            const char *word = argv[6];

            if (!(strcmp(argv[5],"strict")))
            {
                // call to strict
                struct Node *match_strings=strict_match(filename,word);
                printlink(match_strings);
            }
            else if (!(strcmp(argv[5],"pattern")))
            {
                // call to pattern
                struct Node *match_strings=pattern_match(filename,word);
                printlink(match_strings);
            }
            else if (!(strcmp(argv[5],"fuzzy")))
            {
                //call to fuzzy
                struct Node *match_strings=fuzzy_match(filename,word);
                printlink(match_strings);
            }
            else
            {
                printf("Error ! = schema %s not defined", argv[5]);
                printf("Usage : wcomp -f filename -s schema word\n");
            }
        }
        else
        {
            printf("Error ! wrong flag");
            printf("Usage : wcomp -f filename -s schema word\n");
        }
    }
    else
    {
        // printing usage message
        printf("Error! in entering arguments\n");
        printf("Usage : wcomp -f filename -s schema word\n");
    }
    return 0;
}
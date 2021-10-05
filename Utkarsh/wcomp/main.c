#include <stdio.h>
#include "pattern.h"
#include "strict.h"
#include "fuzzy.h"

int main(int argc, char *argv[])
{

    if (argc > 1 && argc < 7)
    {
        if (argv[2] == "-f" && argv[4] == "-s")
        {
            char *filename = argv[3];
            char *word = argv[6];

            if (argv[5] == "strict")
            {
                // call to strict
                strict_match(filename,word);
            }
            else if (argv[5] == "pattern")
            {
                // call to pattern
                pattern_match(filename,word);
            }
            else if (argv[5] == "fuzzy")
            {
                //call to fuzzy
                fuzzy_match(filename,word);
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
}
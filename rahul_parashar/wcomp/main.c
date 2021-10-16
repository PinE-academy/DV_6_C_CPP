#include<stdio.h>
#include<string.h>
#include"strict.h"

int main(int argc, char *argv[])
{
     if (argc > 1 && argc < 7)
    {
        if ((!(strcmp(argv[2],"-f"))) && (!(strcmp(argv[4],"-s"))))
        {
            char *fptr1 = argv[3];
            char *word = argv[6];

            if (!(strcmp(argv[5],"strict")))
            {
                // call to strict
                strict_search(fptr1, word);
            }
            
        }
    }
        return 0;
}


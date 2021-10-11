#include <stdio.h>
#include <stdlib.h>
#include "b_array.h"

b_array *b_create(const unsigned int size)
{

    b_array *arr;

    if (size == 0)
    {
        printf("\nNo size given");
    }

    arr = (b_array *)malloc(sizeof(b_array)); // allocate mem to the structure

    if (arr == NULL)
    {

        printf("\nStruct not allocated");
    }

    else
    {

        arr->size = size;

        arr->array = (unsigned char *)malloc(sizeof(unsigned char) * (((size / 8) + 1))); // alloctae to array

        if (arr->array == NULL)
        {
            printf("\n Array not  allocated");
            free(arr);
            arr = NULL;
        }

        return arr;
    }
}

void b_destroy(b_array *arr)
{

    if (arr != NULL)
    {
        if (arr->array != NULL)
        {
            free(arr->array);
        }
        free(arr);
    }
}

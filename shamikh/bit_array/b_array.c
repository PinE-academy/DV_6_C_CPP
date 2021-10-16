#include <stdio.h>
#include <stdlib.h>
#include "b_array.h"

#define actualPos(bit) ((bit) % 8)

#define actualBit(bit) (1 << actualPos(bit))

#define actualIndex(bit) ((bit) / 8)

b_array *b_create(size_t size)
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
        memset(arr->array, 0, ((size / 8) + 1)); // giving initial values of 0
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

void b_set(b_array *arr, size_t size, enum b_value a)
{

    if (arr == NULL)
    {
        printf("\nEmpty array, try later");
        return 0;
    }

    arr->array[actualIndex(size)] = ((arr->array[actualIndex(size)] & ~actualBit(size) | (a << actualPos(size))));
}

enum b_value b_get(const b_array *arr, size_t size)
{
    if (arr == NULL)
    {
        printf("\nEmpty array, try later");
        exit(1);
    }

    if (arr->array[actualIndex(size)] & (1 << actualPos(size)))
        return b_true;
    else
        return b_false;
}

void b_reset(b_array *arr, size_t size)
{

    if (arr == NULL)
    {
        printf("\nEmpty array, try later");

        arr->array[actualIndex(size)] &= ~(actualBit(size));

        return 0;
    }
}

void b_toggle(b_array *arr, size_t size)
{
    if (arr == NULL)
    {
        printf("\nEmpty array, try later");
        return 0;
    }

    arr->array[actualIndex(size)] ^= (actualBit(size));
}

size_t b_size(b_array *arr)
{
    if (arr == NULL)
    {
        printf("\nEmpty array, try later");
        return 0;
    }

    return arr->size;
}
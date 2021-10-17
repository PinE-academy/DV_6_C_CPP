#include <stdio.h>
#include <stdlib.h>
#include "b_array.h"

int main()
{
    size_t a = 16;
    b_array *bit = b_create(a);

    for (int i = 0; i < (a / 8); i++)
    {
        printf("\n %d", bit->array[i]);         // print all elements of the array
    }

    size_t z = 10;

    printf("\nBefore using any function: %d", b_get(bit, z));

    b_set(bit, z, b_true); //setting the bit z to 1

    printf("\nAfter using Set function: %d", b_get(bit, z));

    b_reset(bit, z); // resetting the location z to 0

    printf("\nAfter using Reset function: %d", b_get(bit, z));

    b_toggle(bit, z); // toggling the bit at position z

    printf("\nAfter using Toggel function: %d", b_get(bit, z));

    printf("\nSize of Arr: %d", b_size(bit)); //print size of thr array

    b_array *copy = b_copy(bit);

    printf("\nAfter using Copy function: %d", b_get(copy, z));

    b_destroy(bit);
}
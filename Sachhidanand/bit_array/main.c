#include<stdio.h>
#include<stdlib.h>
#include"b_array.h"


int main(){
size_t h=24;

    b_array *b = b_create(h);

    for (size_t i = 0; i <(h/8); i++)   //To see the initial value.
    {
        printf("\n%d",b->array[i]);
    }
    
    printf("\n");

    for (size_t i = 0; i <(h/8); i++)
    {
        printf("\t%d",b->array[i]=i+1);
    }
    
    size_t c=10;

    printf("\nBefore using any function: %d",b_get(b,c)); 
       
    b_set(b,c,b_true);
    
    printf("\nAfter using Set function: %d",b_get(b,c));
    
    b_reset(b,c);
    
    printf("\nAfter using Reset function: %d",b_get(b,c));

    b_toggle(b,c);

    printf("\nAfter using Toggel function: %d",b_get(b,c));

    printf("\nSize of Arr: %d", b_size(b));

    b_array *Copied = b_copy(b);

    printf("\nAfter using Copy function: %d",b_get(Copied,c));

}  
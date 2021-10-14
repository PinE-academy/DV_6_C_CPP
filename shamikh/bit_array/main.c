#include<stdio.h>
#include<stdlib.h>
#include"b_array.h"

int main(){
    size_t a;
    b_array *bit= b_create(a);


    for (int i = 0; i < (a/8); i++)
    {
        printf("\n %d", bit->array[i]);
    }

    b_destroy(bit);
     

}
#include<stdio.h>
#include<stdlib.h>
#include"b_array.h"


int main(){
size_t h=24;

    b_array *b = b_create(h);

    for (size_t i = 0; i <(h/8); i++)   //To see the initial value.
    {
        printf("%d\n",b->array[i]);
    }
   

    for (size_t i = 0; i <(h/8); i++)
    {
        printf("%d ",b->array[i]=63*(i+1));
    }
    

}  
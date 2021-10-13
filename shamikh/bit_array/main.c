#include<stdio.h>
#include<stdlib.h>
#include"b_array.h"

int main(){
    const unsigned int a;
    b_array *bit= b_create(a);


    for (int i = 0; i < (a/8); i++)
    {
        printf("\n %d", bit->array[i]);
    }

    
     

}
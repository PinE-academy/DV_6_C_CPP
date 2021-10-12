#include<stdio.h>
#include<stdlib.h>
#include"b_array.h"

#define Index(bit)    ((bit) / 8)

#define Pos(bit)      ((bit) % 8)

b_array *b_create(size_t size){

    b_array *arr;

    //Check if size is 0 or not.
    if(size==0) 
    {
        printf("Can't allow an empty array!");
        return NULL;
    }

    //Dynamically allocating memory.
    arr=(b_array *)malloc(sizeof(b_array));

    if (arr==NULL)
    {
        printf("Error! Try Again");
    }


    else
    {
        arr->size = size;

        arr->array=(unsigned char *)malloc(sizeof(unsigned char)*(((size/8)+1)));    //To get the memory for the number of character bytes we need 

        if(arr->array==NULL)
        {
            printf("Error!");
            free(arr);          //Free the allocated memory if we dont get the memory for bits.
            arr = NULL;
        }

        memset(arr->array, 0 , ((size/8)+1));   //Initialising the values with 0.

    return arr;

    }  
}
void b_destroy(b_array *arr){

   
    if (arr==NULL)
    {
        printf("\nThis is Empty");
        return;
    }
    else
        {
            printf("\n%d Not Empty!");
            if (arr->array!=NULL)
             {
                free(arr->array);
                }
            free(arr);
            printf("\nDone");
        }
}

enum b_value b_get(const b_array *arr, size_t size)
{
    if(arr==NULL)
    {
        printf("Can't find bit in empty array.");
        exit(1);
    }   
    
    if(size > arr->size)
    {
        printf("Position Out of range");
        exit(1);        
    } 
    
    if(arr->array[Index(size)] & (1 << Pos(size)))    
        return b_true;
    else  
        return b_false; 
        
}

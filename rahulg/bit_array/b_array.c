#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"b_array.h"

b_array *b_create(size_t size)
{
	b_array *b_arr;
	
	b_arr = (b_array *)malloc(sizeof(b_array));
	
	if(b_arr == NULL)
	{
		printf("Error ! memory is not allocated");
	}
	
	else
	{
		b_arr->size = size;
		b_arr->array = (char *)malloc(sizeof(char)*(size/8+1)); //memory for character(byte)
		
		if(b_arr->array == NULL)
		{
			printf("Error ! memory is not allocated");
			free(b_arr->array);
			b_arr = NULL;
			
		}
		memset(b_arr->array, 0 ,(size/8+1));// fill memory with 0
		
	return b_arr;
	}
	
}

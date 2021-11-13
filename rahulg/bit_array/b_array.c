#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"b_array.h"

#define Index(loc) loc / 8
#define B_POS(loc)   loc % 8
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
		b_arr->array = (char *)calloc((size/8+1),sizeof(char)); //memory for character(byte)
		
		if(b_arr->array == NULL)
		{
			printf("Error ! memory is not allocated");
			free(b_arr->array);
			b_arr = NULL;
			
		}
		//memset(b_arr->array, 0 ,(size/8+1));/ / fill memory with 0 with malloc
		
	return b_arr;
	}
	
}

void b_destroy(b_array *b_arr)
{
	if(b_arr==NULL)
	{
		printf("\nAlready Memory is not  existed\n");
		
	}
	
	else
	{
		if(b_arr->array==NULL)	
		{
		  	printf("\nAlready bit_Memory is not  existed!\n");
		}
	}
	
	if(b_arr->array!=NULL)	
	{
		b_arr->array=NULL;
		free(b_arr->array);
	
		b_arr=NULL;
		free(b_arr);
	printf("\nMemory is free now\n");
	}
	
}

enum b_value b_get(const b_array *b_arr,size_t loc)
{
	if(b_arr == NULL)
	{
		printf("\nError ! memory is not allocated\n");
	}
	
	if(loc > b_arr->size)
	{
		printf("\n!! Bit Position %zu is out of range\n",loc);
		exit(1);
	}
	printf("\nBinary value in current Byte :");
	arr_bin_print(b_arr->array[Index(loc)]);
	if(b_arr->array[Index(loc)]&(1<<B_POS(loc)))
		return b_true;
	else
		return b_false;
	
}

void b_set(b_array *b_arr,size_t loc,enum b_value binary)
{
	if(b_arr == NULL)
	{
		printf("\nError ! memory is not allocated\n");
	}
	
	if(loc > b_arr->size)
	{
		printf("\n!! Bit Position %zu is out of range\n",loc);
		exit(1);
	}
	
	b_arr->array[Index(loc)]=((b_arr->array[Index(loc)])& ~(1<<B_POS(loc))|binary<<B_POS(loc));
	
printf("\nAfter set function bit value : %d\n",b_get(b_arr,loc));
}

void b_reset (b_array *b_arr,size_t loc)
{
	if(b_arr == NULL)
	{
		printf("\nError ! memory is not allocated\n");
	}
	
	if(loc > b_arr->size)
	{
		printf("\n!! Bit Position %zu is out of range\n",loc);
		exit(1);
	}
	
	b_arr->array[Index(loc)]=((b_arr->array[Index(loc)])& ~(1<<B_POS(loc)));
	printf("\nAfter reset function bit value : %d",b_get(b_arr,loc));
}

void b_toggle (b_array *b_arr,size_t loc)
{
	if(b_arr == NULL)
	{
		printf("\nError ! memory is not allocated\n");
	}
	
	if(loc > b_arr->size)
	{
		printf("\n!! Bit Position %zu is out of range\n",loc);
		exit(1);
	}
	
	b_arr->array[Index(loc)]=((b_arr->array[Index(loc)])^ (1<<B_POS(loc)));
	printf("\nAfter toggle function bit value : %d",b_get(b_arr,loc));
}

size_t b_size(b_array *b_arr)
{
	if(b_arr == NULL)
	{
		printf("\nError ! memory is not allocated\n");
		return 0;
	}
	return (b_arr->size);
}

b_array *b_copy(b_array *b_arr)
{
	if(b_arr == NULL)
	{
		printf("\nError ! memory is not allocated\n");
		exit(1);
	}
	
	b_array *copy=b_create(b_arr->size);
	
	memcpy((copy->array),(b_arr->array),((b_arr->size/8)+1));
	return copy;
}
void arr_bin_print(unsigned char integer)
{
	int i=8;
	printf("\n");
	while(i--)
	{
		printf("\t%d",(integer>>i)&1);
	}
}

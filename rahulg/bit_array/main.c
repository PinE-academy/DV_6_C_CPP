#include<stdio.h>
#include<stdlib.h>
#include"b_array.h"

int main()
{
	b_array *arr = b_create(20);
	
	printf("\n Initial Values : ");
	for (size_t i=0; i<(20/8); i++)
	{
		printf("%d\t",arr->array[i]);
	}
		
	printf("\nvalues in array after storing : ");
	
	for (size_t i=0; i<(20/8); i++)
	{
		printf("%d\t",arr->array[i] = i+1);
	}
	printf("\n");
	return 0;
}

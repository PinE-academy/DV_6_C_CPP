#include<stdio.h>
#include<stdlib.h>
#include"b_array.h"

int main()
{
	size_t h=32;
	size_t bit_pos=9;
	b_array *arr = b_create(h);
	
	printf("\n Initial Values : ");
	for (size_t i=0; i<(h/8); i++)
	{
		printf("%d\t",arr->array[i]);
	}
		
	printf("\nvalues in array after storing : ");
	
	for (size_t i=0; i<(h/8); i++)
	{
		printf("%d\t",arr->array[i] = i+1);
	}
	printf("\n");
	printf("\nInitial value at bit position %zu : %d\n",bit_pos,b_get(arr,bit_pos));
	b_set(arr,bit_pos,b_true);
	printf("\nReset the bit---\n");
	b_reset (arr,bit_pos);
	printf("\nToggle the bit---\n");
	b_toggle (arr,bit_pos);
	printf("\nSize of array : %ld\n",b_size(arr));
	b_array *copy_arr = b_copy(arr);
	printf("\nAfter using Copy function bit value : %d\n",b_get(copy_arr,bit_pos));
	printf("\nToggle the bit---\n");
	b_toggle (arr,bit_pos);
	b_destroy(arr);
	
	return 0;
}

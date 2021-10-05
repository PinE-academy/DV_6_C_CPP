//Definition of functions
typedef struct b_array
{
    unsigned char *array;
    unsigned int bit;
}b_array;

b_array *b_create(size_t size){

    b_array *arr;

    if(size==0)
    {
        printf("Can allow an empty array!");
        return NULL;
    }

    arr=(b_array *)malloc(sizeof(b_array));

    if (arr==NULL)
    {
        printf("Error! Try Again");
    }

    else
    {
        arr->bit= size;

        arr->array=(unsigned char *)malloc(sizeof(unsigned char)*size);

        if(arr->array==NULL)
        {
            printf("Error!");
            free(arr);
            arr = NULL;
        }

    return arr;

    }




    
    
}

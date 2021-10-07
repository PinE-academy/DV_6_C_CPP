//Definition of functions
typedef struct 
{
    unsigned char *array;
    unsigned int bit;

} b_array;

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
        arr->bit = size;

        arr->array=(unsigned char *)malloc(sizeof(unsigned char)*(((size/8)+1)));     //To get the memory for the number of character bytes we need 

        if(arr->array==NULL)
        {
            printf("Error!");
            free(arr);
            arr = NULL;
        }

    return arr;

    }  
}



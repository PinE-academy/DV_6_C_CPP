//Definition of functions
typedef struct 
{
    unsigned char *array;
    unsigned int bit;

} b_array;

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
        arr->bit = size;

        arr->array=(unsigned char *)malloc(sizeof(unsigned char)*(((size/8)+1)));    //To get the memory for the number of character bytes we need 

        if(arr->array==NULL)
        {
            printf("Error!");
            free(arr);          //Free the allocated memory if we dont get the memory for bits.
            arr = NULL;
        }

    return arr;

    }  
}

void b_destroy(b_array *arr){

    if (arr->array!=NULL)
        free(arr->array);   
    if (arr!=NULL)      
        free(arr);
            
}



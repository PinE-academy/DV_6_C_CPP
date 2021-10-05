//Definition of functions

void b_create(int size_t){

    int *array;

    array=(int *)malloc(sizeof(int)*size_t);

    if (array==NULL)
    {
        printf("Error! Try Again");
    }
    
    for(int i=0; i<(sizeof(array)/sizeof(array+0)); i++)
    {
        scanf("%d",*(array+i));
        }
}

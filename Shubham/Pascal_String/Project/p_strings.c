#include"p_strings.h"
#include<stdlib.h>
#include<string.h>

                    //CREATE P_STRING

struct p_strings *p_create(size_t p_size)
{
        struct p_strings *memory = malloc(sizeof(struct p_strings));

        if(memory==NULL)
        return NULL;

        char *character =malloc(p_size);

        if (character==NULL)
        {
            free(memory);
            return NULL;
        }

        memory->length= p_size;
        memory->c_length= character;

        return memory;
};

            // DESTROY P_STRING

void p_destroy(struct p_strings *memory)
{
    free(memory->c_length);
    free(memory);

}

            //READ P_STRING

char p_read(const struct p_strings *memory, size_t p_size)
{

    char p_char= memory-> c_length[p_size];
    return p_char;

}

            // WRITE P_STRINGS

void p_write(struct p_strings *memory, size_t p_size, char p)
{
    memory->c_length[p_size] = p ;
     
}
            // STRING LENGTH P_STRING

size_t p_strlen(const struct p_strings *memory)       
{
    size_t p_length= memory-> length;
    return p_length;
}     


            // STRING COMPARE 
            // It will compare the length of 2 strings

int p_strcmp(const struct p_strings *ptr_1, const struct p_strings *ptr_2)
{
    int i,compare=0;
    for( i=0; i<ptr_1->length; i++ )
        {
            if(ptr_1->length==ptr_2->length)
            {
                if(ptr_1->length==ptr_2->length)
                compare=compare+1;                            // If length is equal then compare value will be updated with the iteration
                else
                compare = ptr_1->c_length[i]-ptr_2->c_length[i];     //size1-size2
            }
            else
            {
                if(ptr_1->length==ptr_2->length)
                compare=compare+1;
                else
                compare = ptr_2->c_length[i]-ptr_1->c_length[i];   // size2 - size1             
            }

        }
    if(compare== ptr_1->length)
        compare= 0;
    else
        return compare;
        
    return compare;

};


            // string concatenation
struct p_strings *p_strcat( struct p_strings *ptr_1, const struct p_strings *ptr_2)
{
 int total = ptr_1->length + ptr_2->length ;
 int j=0,i=ptr_1->length;
 for (i=0;i<=total;i++)
 {
   for(j=0;j<=ptr_2->length;j++)
    {
        ptr_1->c_length[i] = ptr_2->c_length[j];
        i++;
    }
 }
 return ptr_1;
};

           //string copy

struct p_strings *p_strcpy(const struct p_strings *ptr)
{
    struct p_strings *p_ptr= malloc(sizeof(struct p_strings));
    int i;
    p_ptr->length=ptr->length;
        for(i=0 ; i<ptr->length ; i++)
          {
             p_ptr->c_length[i] = ptr->c_length[i];
          }

    return p_ptr;
};

            //string to p_string

struct p_strings *p_string(const char *ptr)
{
    int size = strlen(ptr);
    int i;
    struct p_strings *str = NULL;
    str->length = size-1;
       for(i = 0; i < str->length; i++)
           {
              str->c_length[i] = ptr[i];
           }
    return str;
};            

          //p_string to string

char *to_string(struct p_strings *ptr)
{
    ptr->length+=1;
    char str[ptr->length];
    ptr->c_length[ptr->length]='\0';
         for(int i=0;i<ptr->length;i++)
          {
            str[i] = ptr->c_length[i];
          }
         char *p_string = str;
    return p_string;
};           
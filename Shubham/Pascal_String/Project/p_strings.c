#include"p_strings.h"
#include<stdlib.h>

                    //CREATE P_STRING

struct p_strings *p_create(size_t p_size)
{
        struct p_strings *memory = malloc(sizeof(struct p_strings));

        if(dynamic==NULL)
        return NULL;

        char *character =malloc(p_size);

        if (character==NULL)
        {
            free(dynamic);
            return NULL;
        }

        memory->length= p_size;
        memory->c_length= character;

        return memory;
};

            // DESTROY P_STRING

void p_destroy(struct p_strings *memory)
{
    free(memory->p);
    free(memory);

}

            //READ P_STRING

char p_read(const struct p_strings *memory, size_t p_size)
{

    char p_char= memory-> p[p_size];
    return p_char;

}

            // WRITE P_STRINGS

void p_write(struct p_strings *memory, size_t p_size, char p)
{
    memory->c_length[p_size] = p ;
     
}
            // STRING LENGTH P_STRING

size_t p_strlen(const p_string *memory)       
{
    size_t p_length= memory-> length;
    return p_length;
}     


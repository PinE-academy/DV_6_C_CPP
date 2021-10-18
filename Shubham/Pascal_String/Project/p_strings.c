#include"p_strings.h"
#include<stdlib.h>

                    //CREATE P_STRING

struct p_strings *p_create(size_t p_size)
{
        struct p_strings *dynamic = malloc(sizeof(struct p_strings));

        if(dynamic==NULL)
        return NULL;

        char *character =malloc(p_size);

        if (character==NULL)
        {
            free(dynamic);
            return NULL;
        }

        dynamic->length= p_size;
        dynamic->p= character;

        return dynamic;
};

            // DESTROY P_STRING

void p_destroy(struct p_strings *dynamic)
{
    free(dynamic->p);
    free(dynamic);

}

            //READ P_STRING

char p_read(const struct p_strings *dynamic, size_t p_size)
{

    char p_char= dynamic-> p[p_size];
    return p_char;

}

            // WRITE P_STRINGS

void p_write(struct p_strings *dynamic, char p)
{
    char p_wr[]= dynamic-> gets(p) ;
    return p_wr ;  
}


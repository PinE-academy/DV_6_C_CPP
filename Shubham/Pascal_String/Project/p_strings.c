#include"p_strings.h"
#include<stdlib.h>
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
#include"p_strings.h"
#include<stdlib.h>
//#ifndef abc //Header guard/include guard
//#define abc 

//p_create function
struct p_strings* p_create(size_t p_size){

    struct p_strings *dynamic = malloc(sizeof(struct p_strings));

    if(dynamic == NULL)
        return NULL;

    char *character = malloc(p_size);

    if(character == NULL)
    {    
        free(dynamic);
        return NULL;

    }
    dynamic->size = p_size;
    dynamic->str = character;

    
    return dynamic;
    
};
//#endif

//p_destroy function
void p_destroy(struct p_strings* dynamic)
{
    free(dynamic->str);
    free(dynamic);
};

//p_read function
char p_read(const struct  p_strings* dynamic,size_t p_in)
{
    char p_char = dynamic->str[p_in];
    return p_char;
};

//p_write function
void p_write(struct p_strings*dynamic,size_t p_in,char p_char)
{
    dynamic->str[p_in] = p_char;
};

//p_strlen function
size_t p_strlen(const struct p_strings*dynamic)
{
    return dynamic->size;
};
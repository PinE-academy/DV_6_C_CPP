#include "p_strings.h"
#include <stdlib.h>
#ifndef P_strings
#define P_strings

struct p_strings *p_create(size_t p_size)
{
    struct p_strings *dynamic = malloc(sizeof(struct p_strings));
    if (dynamic == NULL)
        return NULL;
    char *charact = malloc(p_size);
    if (charact == NULL)
    {
        free(dynamic);
        return NULL;
    }
    dynamic->size = p_size;
    dynamic->str = charact;
    return dynamic;
};
//p_destroy func
void p_destroy(struct p_strings* dynamic)
{
    free(dynamic->str);
    free(dynamic);
};
//p_read func
char p_read(const struct  p_strings* dynamic,size_t p_in)
{
    char p_char = dynamic->str[p_in];
    return p_char;
};
#endif

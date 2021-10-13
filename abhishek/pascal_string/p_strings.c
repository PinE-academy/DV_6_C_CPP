#include"p_strings.h"
#include<stdlib.h>
//#ifndef abc //Header guard/include guard
//#define abc 

struct p_strings * p_create(size_t p_size){

    struct p_strings *dynamic = malloc(sizeof(struct p_strings));

    if(dynamic == NULL)
        return NULL;

    char *charact = malloc(p_size);

    if(charact == NULL)
    {    
        free(dynamic);
        return NULL;

    }
    dynamic->size = p_size;
    dynamic->str = charact;

    
    return dynamic;
    
};
//#endif

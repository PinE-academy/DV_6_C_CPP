#include<stdint.h>
struct p_strings
{
    int length;
    char *p;
};
 struct p_strings *p_create(size_t);
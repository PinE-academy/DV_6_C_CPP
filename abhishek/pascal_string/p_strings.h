#include<stdint.h>

struct p_strings
{
    int size;
    char *str;
};
struct p_strings * p_create(size_t);

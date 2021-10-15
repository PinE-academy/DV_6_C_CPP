#include<stdio.h>
#include"p_strings.h"
int main()
{
    size_t p_str_size;
    struct p_strings *p_obj;
    p_obj = p_create(p_str_size);
    p_destroy(p_obj);

    return 0;
}
#include<stdio.h>
#include"p_strings.h"
int main()
{
 size_t Pascal_size;
 char p;
 struct p_strings *pascal_point;
 pascal_point= p_create(Pascal_size);
 p_destroy(pascal_point);
 p_read(pascal_point,Pascal_size);
 p_write(pascal_point,p);
 p_strlen(const pascal_point);

    return 0;
}
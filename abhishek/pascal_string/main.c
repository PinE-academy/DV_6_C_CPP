#include<stdio.h>
#include"p_strings.h"
int main()
{
    size_t p_str_size;
    struct p_strings *p_obj;
    struct p_strings *p_obj1;
    char *str;
    printf("start\n");
    p_obj = p_create(p_str_size); //p_create function call
    printf("pcreate0");
    char main_ch;
    int p_strcmp_value;
    p_str_size = p_strlen(p_obj);
    main_ch = p_read(p_obj,p_str_size);
    p_write(p_obj, p_str_size,main_ch);
    p_str_size = p_strlen(p_obj); 
    p_strcmp_value = p_strcmp(p_obj,p_obj1);
    p_obj = (p_obj,p_obj1);
    p_obj1 = p_strcpy(p_obj);
    p_obj = p_string(str);
    str =string(p_obj);
    printf("\n%d",p_obj->size);
    printf("\n%s",p_obj->str);
    //p_destroy(p_obj);


    return 0;
}
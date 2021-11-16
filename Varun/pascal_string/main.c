#include<stdio.h>
#include"p_strings.h"

int main()
{
    size_t p_str_size = 9;
    struct p_strings *p_obj = NULL;
    struct p_strings *p_obj1 = NULL;
   // struct p_strings *p_obj2;
    char *str = "Using functions of Header";
    printf("started\n");
    p_obj = p_create(p_str_size); //p_create function call
    printf("Working...");
    char main_ch;
    int p_strcmp_value = 1;
    p_str_size = p_strlen(p_obj);
    main_ch = p_read(p_obj,p_str_size);
    p_write(p_obj, p_str_size,main_ch);
    p_str_size = p_strlen(p_obj); 
    p_strcmp_value = p_strcmp(p_obj,p_obj1);
    printf("%d",p_strcmp_value);
    p_obj = p_strcat(p_obj,p_obj1);
    p_obj1 = p_strcpy(p_obj);
    p_obj = p_string(str);
    str =string(p_obj);
    p_destroy(p_obj);
    return 0;
}

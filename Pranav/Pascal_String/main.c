#include"p_strings.h"
int main()
{
    size_t p_str_size = 10;
    struct p_strings *p_obj_1 = NULL;
    struct p_strings *p_obj_2 = NULL;
    char *str = "Here we go again";
    printf("Kick Off \n");
    p_obj_1 = p_create(p_str_size);
    printf("---Pascal String 1 Create---\n");
    char A;
    int pstr_cmp = 1;
    p_str_size = p_strlen(p_obj_1);
    A = p_read(p_obj_1,p_str_size);
    p_write(p_obj_1,p_str_size,A);
    p_str_size = p_strlen(p_obj_1);
    pstr_cmp = p_strcmp(p_obj_1,p_obj_2);
    printf("%d",pstr_cmp);
    p_obj_1 = p_strcat(p_obj_1,p_obj_2);
    p_obj_2 = p_strcpy(p_obj_1);
    p_obj_2 = p_string(str);
    str = string(p_obj_1);
    printf("----- wrap up -----");
    return 0;
}
#include<stdio.h>
#include"p_strings.h"
int main()
{
 size_t Pascal_size=20;
 struct p_strings *pascal_point1=NULL;
 struct p_strings *pascal_point2=NULL;
 char *string2 = "I am trying pascal string";
 printf("Start \n");
 pascal_point1 = p_create(Pascal_size);
 printf("Create one string \n");
 char p;
 int string_cmp = 1;
 Pascal_size = p_strlen(pascal_point1);
 p= p_read(pascal_point1,Pascal_size);
 p_write(pascal_point1,Pascal_size,p);
 Pascal_size = p_strlen(pascal_point1);
 string_cmp = p_strcmp(pascal_point1,pascal_point2);
 printf("%d",string_cmp);
 pascal_point1 = p_strcat(pascal_point1,pascal_point2);
 pascal_point2 = p_strcpy(pascal_point1);
 pascal_point2 = p_string(string2);
 string2 = string(pascal_point1);
    printf("FINISH");

    return 0;
}
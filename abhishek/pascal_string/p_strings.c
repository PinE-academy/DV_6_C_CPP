#include"p_strings.h"
#include<stdlib.h>
#include<string.h>

//#ifndef abc //Header guard/include guard
//#define abc 

//p_create function
struct p_strings* p_create(size_t p_size){

    struct p_strings *dynamic = malloc(sizeof(struct p_strings));

    if(dynamic == NULL)
        return NULL;

    char *character = malloc(p_size);

    if(character == NULL)
    {    
        free(dynamic);
        return NULL;

    }
    dynamic->size = p_size;
    dynamic->str = character;

    
    return dynamic;
    
};
//#endif

//p_destroy function
void p_destroy(struct p_strings* dynamic)
{
    free(dynamic->str);
    free(dynamic);
};

//p_read function
char p_read(const struct  p_strings* dynamic,size_t p_in)
{
    char p_char = dynamic->str[p_in];
    return p_char;
};

//p_write function
void p_write(struct p_strings*dynamic,size_t p_in,char p_char)
{
    dynamic->str[p_in] = p_char;
};

//p_strlen function
size_t p_strlen(const struct p_strings*dynamic)
{   
    size_t pstr_len = dynamic->size;
    return pstr_len;
}; 

/*
//p_strcmp function
int p_strcmp(const struct p_strings*p_str1, const struct p_strings *p_str2)
{
    int cmp_value=0;
    if(p_str1->size == p_str2->size)
    {
        for(int i=0;i<p_str2->size;i++)
        {
           if(p_str1->str[i]==p_str2->str[i])
                cmp_value = cmp_value+1;
            else 
                cmp_value = p_str1->str[i]-p_str2->str[i];
            
        }
        if(cmp_value == p_str2->size)
            cmp_value = 0;
        
        else 
            return cmp_value;
    }
    else if(p_str1->size > p_str2->size)
       {
           for(int i=0;i<p_str1->size;i++)
           {
               if(p_str1->str[i] == p_str2->str[i])
                cmp_value = cmp_value+1;
            else 
                cmp_value = p_str1->str[i]-p_str2->str[i];
                
           }
       }
    else
        {
           for(int i=0;i<p_str2->size;i++)
           {
               if(p_str1->str[i] == p_str2->str[i])
                cmp_value = cmp_value+1;
            else 
                cmp_value = p_str2->str[i]-p_str1->str[i];
                
           }
       }
        
    return cmp_value;
    
};

*/

//p_strcmp function
int p_strcmp(const struct p_strings*p_str1, const struct p_strings *p_str2)
{
    int cmp_value=0;
    for(int i=0;i< p_str1->size; i++)
    {
       if(p_str1->size == p_str2->size)
       {
          if(p_str1->str[i]==p_str2->str[i])
                cmp_value = cmp_value+1;
            else 
                cmp_value = p_str1->str[i]-p_str2->str[i]; 
       }
       else
       {
        if(p_str1->str[i] == p_str2->str[i])
                cmp_value = cmp_value+1;
            else 
                cmp_value = p_str2->str[i]-p_str1->str[i];
        }
    }
    return cmp_value;
};

//p_strcat function
struct p_strings* p_strcat(struct p_strings* p_str1,const struct p_strings* p_str2)
{
    //struct p_strings* p_concat;
    int size = p_str1->size + p_str2->size;
    int i = p_str1->size, j = 0;
    p_str1->size = size;
    while (i<=size) 
    {
        p_str1->str[i] = p_str2->str[j];
        i++;
        j++;
    }

    return p_str1;
};

//p_strcpy function
struct p_strings* p_strcpy(const struct p_strings*p_str)
{
    struct p_strings* p_copy= malloc(sizeof(struct p_strings));
    p_copy->size=p_str->size;
    for(int i=0 ; i<p_str->size ; i++)
    {
        p_copy->str[i] = p_str->str[i];
    }

    return p_copy;
};

//string to p_string conversion function
struct p_strings* p_string(const char *str)
{
    int str_size=strlen(str);
    struct p_strings* p_str = NULL;
    p_str->size = str_size-1;
    for(int i = 0; i < p_str->size; i++)
    {
           p_str->str[i] = str[i];
    }
    return p_str;
};

//p_string to string conversion function
char* string(struct p_strings* p_str)
{
    p_str->size+=1;
    char str[p_str->size];
    p_str->str[p_str->size]='\0';
    for(int i=0;i<p_str->size;i++)
    {
        str[i] = p_str->str[i];
    }
    char *string = str;
    return string;
};


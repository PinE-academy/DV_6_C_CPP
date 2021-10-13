#include<stdint.h>
struct p_strings //create p_string
{
    int size;
    char *str;
};struct p_strings * p_create(size_t); 

void p_destroy(p_string*); //destroy p_string

char read(const p_string*, size_t); //read p_string

void write(p_string*, char); //write p_string

size_t pstrlen(const p_string *); //string length

int pstrcmp(const p_string *, const p_string *); //string compare

p_string* pstrcat(p_string *, const p_string *); //string concatenation

p_string pstrcpy(const p_string*); //string copy

p_string* toP_string(const char *); //string to p_string

char* toString(p_string*); //p_string to string
#include<stdint.h>
#include<stdlib.h>
struct p_strings
{
    int size;
    char *str;
};
struct p_strings* p_create(size_t);
void p_destroy(struct p_strings*);
char p_read(const struct p_strings*,size_t);
void p_write(struct p_strings*,size_t,char);
size_t p_strlen(const struct p_strings*); 
int p_strcmp(const struct p_strings*,const struct p_strings*);
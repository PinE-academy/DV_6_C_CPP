#include<stdint.h>

struct p_strings
{
    int size;
    char *str;
};
struct p_strings* p_create(size_t);
void p_destroy(struct p_strings*);
char p_read(const struct p_strings*,size_t);
 
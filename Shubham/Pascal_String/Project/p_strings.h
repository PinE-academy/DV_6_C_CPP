#include<stdint.h>
struct p_strings
{
    int length;
    char *c_length ;
};
 struct p_strings *p_create(size_t);
 void p_destroy(struct p_strings *);
 char p_read(const struct p_strings*, size_t);
 void p_write(struct p_strings *, size_t, char);
 size_t p_strlen(const struct p_strings *);   
 int p_strcmp(const struct p_strings *, const struct p_strings *);
 struct p_strings *p_strcat(struct p_strings *, const struct p_strings *);
 struct p_strings *p_strcpy(const struct p_strings*);
 struct p_strings *p_string(const char *);
 char* to_string(struct p_strings*);

 

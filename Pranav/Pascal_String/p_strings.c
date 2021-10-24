#include"p_strings.h"
struct p_strings* p_create(size_t p_size){
    struct p_strings *pstr = malloc(sizeof(struct p_strings));
    if(pstr==NULL)
        return NULL;
    char *pchar = malloc(p_size);
    if(pchar==NULL){
        free(pstr);
        return NULL;
    }
    pstr->sops=p_size;
    pstr->cops=pchar;
    return pstr;
};
void p_destroy(struct p_strings *pstr){
    free(pstr->cops);
    free(pstr);
};
char p_read(const struct p_strings *pstr,size_t index){
    char pchar = pstr->cops[index];
    return pchar;
};
void p_write(struct p_strings *pstr, size_t index ,char pchar){
    pstr->cops[index]=pchar;
};
size_t p_strlen(const struct p_strings *pstr){
    return pstr->sops;
};
int p_strcmp(const struct p_strings *pstr1, const struct p_strings *pstr2){
    int diff=0;
    for(int i=0;i<pstr1->sops;i++){
        if(pstr1->sops == pstr2->sops)
       {
          if(pstr1->cops[i]==pstr2->cops[i])
                diff = diff+1;
            else 
                diff = pstr1->cops[i]-pstr2->cops[i]; 
       }
       else
       {
        if(pstr1->cops[i] == pstr2->cops[i])
                diff = diff+1;
            else 
                diff = pstr2->cops[i]-pstr1->cops[i];
        }
    }
    return diff;
};
struct p_strings* p_strcat(struct p_strings* pstr1,const struct p_strings* pstr2)
{
    int size = pstr1->sops + pstr2->sops;
    int i = pstr1->sops, j = 0;
    pstr1->sops = size;
    while (i<=size) 
    {
        pstr1->cops[i] = pstr2->cops[j];
        i++;
        j++;
    }
    return pstr1;
};
struct p_strings* p_strcpy(const struct p_strings*pstr)
{
    struct p_strings* pcpy= malloc(sizeof(struct p_strings));
    pcpy->sops=pstr->sops;
    for(int i=0 ; i<pstr->sops ; i++)
    {
        pcpy->cops[i] = pstr->cops[i];
    }

    return pcpy;
};
struct p_strings* p_string(const char *cops)
{
    int cops_size=strlen(cops);
    struct p_strings* pstr = NULL;
    pstr->sops = cops_size-1;
    for(int i = 0; i < pstr->sops; i++)
    {
           pstr->cops[i] = cops[i];
    }
    return pstr;
};
char* string(struct p_strings* pstr)
{
    pstr->sops+=1;
    char cops[pstr->sops];
    pstr->cops[pstr->sops]='\0';
    for(int i=0;i<pstr->sops;i++)
    {
        cops[i] = pstr->cops[i];
    }
    char *string = cops;
    return string;
};



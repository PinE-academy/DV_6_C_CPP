typedef struct {
    struct GList *gnode;
} GIter;

GIter* new_gIter(GList *list){
    struct GIter *iter = (struct GIter*)malloc(sizeof(struct GIter));
    iter -> gnode = list;
}

void free_gIter(GIter *iter)
{
    free(iter);
}

void gIter_next(GIter *iter)
{
    iter -> gnode = iter -> gnode -> next;
}

int gIter_IsNull(GIter *iter)
{
    if(iter -> gnode == NULL)
    return 1;
    else return 0;
}

void* gIter_value(GIter *iter)
{
    return (iter -> gnode ->data);
}
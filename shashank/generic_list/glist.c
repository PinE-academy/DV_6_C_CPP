typedef struct {
    void *data;
    struct GList *next;
} GList;

Glist* new_gList()
{
	struct GList *x = (struct GList*)malloc(sizeof(struct GList));
	x->data = 0;
	x->next= NULL;
	return x;
}

void free_gList(GList *p)
{
	free(p);
}

#define glist_insert(a,b,c) glist_insert2(a,&b,sizeof(b),c) 

void gList_insert2(Glist *list,void* data,int size,int index)
{
    int i;

    void *d = malloc(size);
    memcpy(d,data,size);

    list->data =d;

}


void* gList_at(Glist *list,int index)
{
    Glist *temp = list;
    for (i=1; i<index; i++)
    {
        if(temp->next != NULL)
        {
            temp=temp->next;
        }
        printf("The value at this index is: %d",temp->data);    
    }
}
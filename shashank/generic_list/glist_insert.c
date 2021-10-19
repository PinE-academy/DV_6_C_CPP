
#define glist_insert(a,b,c) glist_insert2(a,&b,sizeof(b),c) 

void gList_insert2(Glist *list,void* data,int size,int index)
{
    int i;

    void *d = malloc(size);
    memcpy(d,data,size);

    list->data =d;

    if(index == 0)
    {
        //insert at first position
    }
    
    for (i=0; i<index; i++)
    {
        // traversal to the node where data is to be inserted.
    }
}
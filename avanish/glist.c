typedef struct {
    void *data;
    struct GList *next;
} GList;

GList* new_gList()
{
    struct node *head = null;
	head = (struct GList*)malloc(sizeof(struct GList));
    head -> data=null;
    head -> next = null;
    return head;

}


void free_gList(GList *head)
{
	struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp -> next;
        free(head);
        head = temp;
    }
    return head;
}


#define glist_insert(list, data,index) glist_insert2(list, &data, sizeof(data), int index)

void gList_insert2(GList *list, void *data,int data_size, int index)
{
    void *d = malloc(data_size);
    memcpy(d, data, data_size);

    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2 -> data = d;
    ptr2 -> link = NULL;

    index--;
    while(index != 1)
    {
        ptr = ptr -> link;
        index-- ;
    }
    ptr2 -> link = ptr -> link;
    ptr -> link = ptr2;
}



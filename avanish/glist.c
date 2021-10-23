typedef struct {
    void *data;
    struct GList *next;
} GList;

GList* new_gList()
{
    struct GList *head = NULL;
	head = (struct GList*)malloc(sizeof(struct GList));
    head -> data= NULL;
    head -> next = NULL;
    return head;

}


void free_gList(GList *head)
{
	struct GList *temp = head;
    while (temp != NULL)
    {
        temp = temp -> next;
        free(head);
        head = temp;
    }
    return head;
}


#define glist_insert(list, data, index) glist_insert2(list, &data, sizeof(data), int index)

void gList_insert2(GList *list, void *data,int data_size, int index)
{
    void *d = malloc(data_size);
    memcpy(d, data, data_size);

    struct GList *ptr = head;
    struct GList *ptr2 = (struct GList*)malloc(sizeof(struct Glist));
    ptr2 -> data = d;
    ptr2 -> next = NULL;

    index--;
    while(index != 1)
    {
        ptr = ptr -> next;
        index-- ;
    }
    ptr2 -> next = ptr -> next;
    ptr -> next = ptr2;
}

void* gList_at(GList * list, size_t index)
{
    struct GList *ptr = NULL;
    ptr = head;
    int count = 1;
    while(count != index){
    count ++;
    ptr = ptr -> next;
    }
    return (ptr -> data);
}


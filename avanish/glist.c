typedef struct {
    void *data;
    struct GList *next;
} GList;

GList* new_gList()
{
    struct node *head = null;
	head = (struct GList*)malloc(sizeof(struct GList));
    head -> data=0;
    head -> next = null;
    return head;

}


void free_gList(GList *head)
{
	struct node *temp = head;
    while (temp != null)
    {
        temp = temp -> next;
        free(head);
        head = temp;
    }
    return head;
}
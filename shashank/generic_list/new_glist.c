glist* new_gList(glist** head,int size)
{
	struct GList *x = (struct GList*)malloc(sizeof(struct GList));
	x->data = malloc(size);
	x->next= head;
	return x;
}
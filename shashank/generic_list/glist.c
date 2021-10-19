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


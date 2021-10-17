typedef Struct{
  void*data;
  Struct glist*next;
}glist;
glist*new_glist()
{
  Struct node*head=null;
     head= (Struct glist*)malloc(sizeof(stuct glist));
  head-> data=0;
  head-> next= null;
  return head;
}
    
void free_glist(glist*head)
{
  struct node*temp=head
 while (temp!=null)
 {
   temp= temp-> next;
   free(head);
   head=temp;
 }
  return head;
}

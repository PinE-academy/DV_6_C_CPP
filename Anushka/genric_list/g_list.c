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
    

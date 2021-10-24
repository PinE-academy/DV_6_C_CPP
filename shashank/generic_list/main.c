#include<stdio.h>
#include<stdlib.h>


void main()
{
    Glist *new = new_glist();

    int a,i;
    printf("Enter the data : ");
    scanf("%d",&a);    
    printf("\n");
    printf("Enter the Index : ");
    scanf("%d",&i);
    printf("\n");
   
    glist_insert(new,a,i);

    Glist *head,*temp;
    temp = head;

    if(index == 0)
        head=new;//insert at first position
    else// traversal to the node where data is to be inserted.
    for (i=1; i<index-1; i++)
    {
        if(temp->next != NULL)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;    
    }

    i=0;
    printf("Get the value at the Index : ");
    scanf("%d",&i);
    printf("\n");

    gList_at(head,i);

}
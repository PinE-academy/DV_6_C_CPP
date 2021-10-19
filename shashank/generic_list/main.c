#include<stdio.h>


void main()
{
    Glist *new = new_glist();

    int a,i;
    printf("Enter the data : ");
    scanf("%d",&a);    
    printf("Enter the Index : ");
    scanf("%d",&i);

    glist_insert(new,a,i);
    

}
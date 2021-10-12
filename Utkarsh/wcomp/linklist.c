#include<stdio.h>
#include<stdlib.h>
#include"link.h"
struct Node{
    char *data;
    struct Node *next;
};

// create new link
struct Node *createlink(struct Node *head){
    head=NULL;
    return head;
}

//insert at the End
int insertEnd(struct Node **head,char *data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    if (*head == NULL)
    {
        *head = node;
    }
    else
    {
        struct Node *temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // link at end
        temp->next = node;
    }

    return 0;
}
// print the linked list
void printlink(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
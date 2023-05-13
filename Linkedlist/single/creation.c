#include <stdio.h>
#include <stdlib.h>
// defining my own datatype
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *newnode, *ptr; // ptr is used to name the newnode when it is linked in the LL
    int choice = 1;
    head = NULL;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = ptr = newnode;
        }
        else
        {
            ptr->next = newnode;
            ptr = newnode;
        }
        printf("Do you still wanna continue?(0/1): ");
        scanf("%d", &choice);
    }

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * prev;
    int data;
    struct node * next;
};

int main () {
    struct node *head, *ptr, *newnode;
    int choice = 1;
    head = NULL;
    ptr = head;

    while (choice) {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf ("Enter data : ");
    scanf ("%d", & newnode->data);
    newnode-> prev = newnode-> next = NULL;
    if (head==NULL) {
        head = ptr = newnode;
    }
    else {
        ptr-> next = newnode;
        newnode-> prev = ptr;
        ptr = newnode;
    }
    printf ("continue?(0/1): ");
    scanf ("%d", &choice);
    }

    ptr = head;
    while (ptr!= NULL) {
        printf ("%d  ", ptr-> data);
        ptr = ptr-> next;
    }

}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *first = NULL;

void insertintoLinkedList(int data)
{

    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory Not Available ...\n");
        return;
    }

    new_node->data = data;
    new_node->link = NULL;

    if (first == NULL)
    {
        first = new_node;
        return;
    }

    struct node *next = first;

    while (next->link != NULL)
    {
        next = next->link;
    }

    next->link = new_node;
}

void reverseLinkedList()
{

    struct node *current = first;
    struct node *prev = NULL;
    struct node *next = NULL;

    while (current != NULL)
    {

        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    first = prev;
}

void printLinkedList()
{

    if (first == NULL)
    {
        printf("Linked List is Empty ...");
        return;
    }

    struct node *next = first;

    while (next != NULL)
    {
        printf("%d->", next->data);
        next = next->link;
    }
    printf("NULL\n");
}

void main()
{

    insertintoLinkedList(1);
    insertintoLinkedList(2);
    insertintoLinkedList(3);
    insertintoLinkedList(4);
    insertintoLinkedList(5);
    printLinkedList();

    reverseLinkedList();
    printLinkedList();
}

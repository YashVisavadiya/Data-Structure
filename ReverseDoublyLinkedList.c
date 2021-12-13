#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};

struct node *leftmost = NULL;
struct node *rightmost = NULL;

void insertatLeft(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory Not Available ...\n");
        return;
    }

    new_node->data = data;
    new_node->lptr = NULL;

    if (leftmost == NULL)
    {
        leftmost = new_node;
        rightmost = new_node;
        new_node->rptr = NULL;
        return;
    }

    leftmost->lptr = new_node;
    new_node->rptr = leftmost;
    leftmost = new_node;
}

void insertatRight(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory Not Available ...\n");
        return;
    }

    new_node->data = data;
    new_node->rptr = NULL;

    if (rightmost == NULL)
    {
        rightmost = new_node;
        leftmost = new_node;
        new_node->lptr = NULL;
        return;
    }

    rightmost->rptr = new_node;
    new_node->lptr = rightmost;
    rightmost = new_node;
}

void printDoublyLinkedList()
{
    if(leftmost==NULL)
    {
        printf("Empty\n");
        return;
    }

    struct node *next;
    next=leftmost;

    while(next!=NULL)
    {
        printf("%d-><-",next->data);
        next=next->rptr;
    }
    printf("NULL\n");
}

void reverseDoublyLinkedList()
{
    struct node *current=leftmost;
    struct node *prev=NULL;
    struct node *next=NULL;

    while(current!=NULL)
    {
        next=current->rptr;
        current->rptr=prev;
        current->lptr=next;
        prev=current;
        current=next;

    }
    rightmost=leftmost;
    leftmost=prev;
}

void main()
{
    insertatLeft(1);
    insertatLeft(2);
    insertatRight(3);
    insertatRight(4);
    insertatLeft(5);

    printDoublyLinkedList();

    reverseDoublyLinkedList();
    printDoublyLinkedList();
}

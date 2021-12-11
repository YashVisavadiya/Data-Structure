#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *first = NULL;
struct node *last = NULL;

void insert(int data)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));

    if(new_node==NULL)
    {
        printf("Memory NOt Available ...\n");
        return;
    }

    new_node->data=data;
    new_node->link=NULL;

    if(first==NULL)
    {
        first=new_node;
        last=new_node;
        return;
    }

    last->link=new_node;
    last=new_node;
}

void print()
{
    if(first==NULL)
    {
        printf("Empty ...\n");
        return;
    }

    struct node *next=first;

    while(next!=last)
    {
        printf("%d->",next->data);
        next=next->link;
    }
    printf("%d->First\n",next->data);
}

void reverse()
{
    struct node *current=first;
    struct node *prev=last;
    struct node *next=NULL;

    while(current!=last)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    current->link=prev;
    last=first;
    first=current;
}

void main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();

    reverse();
    print();
}

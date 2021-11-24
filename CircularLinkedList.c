#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

struct node *first,*last;

void print()
{
    printf("1.Insert a node at the front of the linked list : \n");
    printf("2.Delete a node from specified position : \n");
    printf("3.Insert a node at The end Of The Linked list : \n");
    printf("4.Display ALL Nodes : \n");
    printf("0.Exit \n");
}

void menu()
{
    int choice;
    do
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                insertatFront();
                break;
            }
            case 2:
            {
                deletefromspecifiedvalue();
                break;
            }
            case 3:
            {
                insertNodeatEnd();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 0:
            {
                break;
            }
            default :
            {
                printf("Please Enter Correct Choice ... \n");
            }
        }
    }while(choice!=0);
}

void insertatFront()
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));

    if(new==NULL)
    {
        printf("Memory is not Available...\n");
        exit(1);
    }

    printf("Enter a Value to insert : ");
    scanf("%d",&new->data);

    if(first==NULL)
    {
        first=new;
        last=new;
        first->link=first;
        return;
    }

    new->link=first;
    first=new;
}

void deletefromspecifiedvalue()
{
    int value;

    if(first==NULL && last == NULL)
    {
        printf("Underflow\n");
        return;
    }

    printf("Enter Value of node to delete that node : ");
    scanf("%d",&value);

    struct node *next,*pred;
    next=first;
    while(next!=last && next->data!=value)
    {
        pred=next;
        next=next->link;
    }

    if(next==first)
    {
        last->link=first->link;
        free(first);
        first=last->link;
        return;
    }
    if(next==last && next->data==value)
    {
        pred->link=next->link;
        last=pred;
        free(next);
        return;
    }
    if(next->data==value)
    {
        pred->link=next->link;
        free(next);
        return;
    }
    
    if(next==last && next->data!=value)
    {
        printf("Value node found in linked list ...\n");
        return;
    }
}

void deleteFirst()
{
    if(first==NULL)
    {
        printf("Underflow\n");
        return;
    }

    if(first==last)
    {
        first=NULL;
        last=NULL;
        return;
    }
    last->link=first->link;
    free(first);
    first=last->link;
}

void deleteLast()
{
    struct node *pred;
    pred=first;

    if(last==NULL)
    {
        printf("Underflow\n");
        return;
    }

    if(last==first)
    {
        first=NULL;
        last=NULL;
        return;
    }

    while(pred->link!=last)
    {
        pred=pred->link;
    }
    pred->link=last->link;
    last=pred;
}

void display()
{
    struct node *next;
    next=first;

    if(first==NULL)
    {
        printf("Underflow \n");
        return;
    }

    while(next!=last)
    {
        printf("%d ",next->data);
        next=next->link;
    }
    printf("%d \n",next->data);
}

void main()
{
    print();
    menu();
}
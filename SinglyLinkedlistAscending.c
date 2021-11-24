#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

struct node *first;
//first=NULL;

void print()
{
    printf("1.Insert a node such that linked list is in ascending order : \n");
    printf("2.Delete a node from specified position : \n");
    printf("3.Delete a first node of the linked list : \n");
    printf("4.Delete a last node of The Linked list : \n");
    printf("5.Display \n");
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
                insertinAscending();
                break;
            }
            case 2:
            {
                deletefromspecifiedvalue();
                break;
            }
            case 3:
            {
                deleteFirst();
                break;
            }
            case 4:
            {
                deleteLast();
                break;
            }
            case 5:
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

void insertinAscending()
{
    struct node *new,*next;
    new=(struct node *)malloc(sizeof(struct node));

    if(new==NULL)
    {
        printf("Memory Is Not Available ...\n");
        exit(1);
    }

    printf("Enter a Value to Insert : ");
    scanf("%d",&new->data);

    if(first==NULL)
    {
        first=new;
        first->link=NULL;
        return;
    }

    if(new->data<=first->data)
    {
        new->link=first;
        first=new;
        return;
    }
    next=first;
    while(next->link!=NULL && new->data>=next->link->data)
    {
        // pred=next;
        next=next->link;
    }
    
    new->link=next->link;
    next->link=new;
}

void deletefromspecifiedvalue()
{
    int value;
    printf("Enter Value of node to delete that node : ");
    scanf("%d",&value);

    struct node *next,*pred;
    next=first;
    while(next!=NULL && next->data!=value)
    {
        pred=next;
        next=next->link;
    }
    if(next==NULL)
    {
        printf("Value node found in linked list ...\n");
        return;
    }
    pred->link=next->link;
    free(next);
}

void deleteFirst()
{
    if(first==NULL)
    {
        printf("Underflow\n");
        return;
    }
    struct node *temp;
    temp=first->link;
    free(first);
    first=temp;
}

void deleteLast()
{
    if(first==NULL)
    {
        printf("Underflow\n");
        return;
    }
    struct node *next,*pred;
    next=first;
    while(next->link!=NULL)
    {
        pred=next;
        next=next->link;
    }
    free(next);
    pred->link=NULL;
}

void display()
{
    struct node *next;
    next=first;
    if(first==NULL)
    {
        printf("Underflow\n");
        return;
    }
    while(next!=NULL)
    {
        printf("%d ",next->data);
        next=next->link;
    }
    printf("\n");
    return;
}

void main()
{
    print();
    menu();
}
#include<stdio.h>
#include<stdlib.h>

struct node *first;
int totalNode=0;

struct node
{
    int data;
    struct node *link;
};

struct node *CreateNodeAtfirst()
{
    struct node *ptr=NULL;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nMemory is Full...");
        exit(1);
    }
    printf("\nEnter a Value To Insert : ");
    scanf("%d",&ptr->data);
    ptr->link=first;
    return ptr;
}

void displayAll()
{
    struct node *next;
    next=first;
    printf("\n%d ",next->data);
    for(int i=2;i<=totalNode;i++)
    {
        next=next->link;
        printf("%d ",next->data);
    }
    printf("\n");
}

struct node *deleteFirst()
{
    struct node *temp;
    temp=first->link;
    totalNode--;
    return temp;
}

struct node *traverseTolast()
{
    struct node *next,*pre;
    next=first;

    while(next!=NULL)
    {
        pre=next;
        next=next->link;
    }
    return pre;
}

void insertAtend()
{
    struct node *last,*new;

    last=traverseTolast();
    
    new=(struct node *)malloc(sizeof(struct node));
    last->link=new;
    printf("Enter a Value To Insert : ");
    scanf("%d",&new->data);
    new->link=NULL;
    totalNode++;
}

void deleteLast()
{
    struct node *last;

    last=traverseTolast();
    free(last);
    totalNode--;
}

void deleteAtposition(int position)
{
    struct node *next,*pre;
    next=first;
    int counter=0;

    while(counter!=position)
    {
        pre=next;
        next=next->link;
        counter++;
    }
        pre->link=next->link;
        totalNode--;
        return;
}

void main()
{
    int choice;
    struct node *ptr;

    ptr=NULL;
    first=NULL;

    printf("1.Create a Node at Front of Linked List :\n");
    printf("2.Display All Node : \n");
    printf("3.Delete a First Node of a Linked list :\n");
    printf("4.Insert a Node at the End of The Linked List : \n");
    printf("5.Delete a Last Node of the Linked List :\n");
    printf("6.Delete a Node From Specified Position : \n");
    printf("0.Exit");

    do
    {
        printf("Enter Your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                first=CreateNodeAtfirst();
                totalNode++;
                break;
            }
            case 2:
            {
                displayAll();
                break;
            }
            case 3:
            {
                first=deleteFirst();
                break;
            }
            case 4:
            {
                insertAtend();
                break;
            }
            case 5:
            {
                deleteLast();
                break;
            }
            case 6:
            {
                int position;
                printf("Enter Position of node after first : ");
                scanf("%d",&position);

                deleteAtposition(position);
                break;
            }
            default:
            {
                printf("Please Enter correct choice ...\n");
                break;
            }
        }
    }while(choice!=0);
}

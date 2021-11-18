#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node *first,*top;
// first=NULL;
// top=NULL;

void Push()
{
    struct node *ptr,*temp;
    temp=top;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nStack Overflow\n");
        return;
    }
    if(first==NULL && top==NULL)
    {
        first=ptr;
        top=ptr;
        // top->link=NULL;
    }
    else
    {
        top=ptr;
    }
    printf("Enter a Value to Insert( Push ) :");
    scanf("%d",&top->data);
    top->link=temp;
    printf("Successfully Pushed %d in Stack \n",top->data);
}

void Pop()
{
    struct node *successor;
    successor=top->link;
    int x;

    if(top==NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }

    x=top->data;
    free(top);
    top=successor;
    printf("Poped Value is %d \n",x);
}

void Display()
{
    struct node *next;
    next=top;

    while(next!=NULL)
    {
        printf("%d ",next->data);
        next=next->link;
    }
    printf("\n");

}

void main()
{
    printf("1.Push \n");
    printf("2.Pop \n");
    printf("3.Display \n");
    printf("0.Exit \n");

    int choice;

    do
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                Push();
                break;
            }
            case 2:
            {
                Pop();
                break;
            }
            case 3:
            {
                Display();
                break;
            }
            default:
            {
                printf("\nPlease Enter Correct Choice...\n");
            }
        }
    }while(choice!=0);

}

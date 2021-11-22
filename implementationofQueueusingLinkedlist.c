#include<stdio.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front,*rear;

void Enqueue()
{
    struct node *ptr,*predecessor;
    predecessor=rear;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Overflow\n");
        return;
    }
    if(front==NULL && rear==NULL)
    {
        front=ptr;;
        rear=ptr;
    }
    else
    {
        rear=ptr;
        predecessor->link=rear;
    }
    rear->link=NULL;
    printf("Enter a Value to Insert : ");
    scanf("%d",&rear->data);
    printf("Successfully Enqueue %d in Queue \n",rear->data);
}

void Dequeue()
{
    int x;
    struct node *temp;
    temp=front->link;
    if(front==NULL)
    {
        printf("Underflow \n");
        exit(1);
    }
    x=front->data;
    free(front);
    front=temp;
    printf("Dequeued Value is %d \n",x);
}

void Display()
{
    struct node *next;
    next=front;

    if(front==NULL)
    {
        printf("Underflow \n");
        return;
    }

    while(next!=NULL)
    {
        printf("%d ",next->data);
        next=next->link;
    }
    printf("\n");
}

void main()
{
    printf("1.Insert a Element (Enqueue) : \n");
    printf("2.Delete a Element (Dequeue) : \n");
    printf("3.Display : \n");
    printf("0.Exit \n");

    int choice;

    do
    {
        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                Enqueue();
                break;
            }
            case 2:
            {
                Dequeue();
                break;
            }
            case 3:
            {
                Display();
                break;
            }
            default:
            {
                printf("Please Enter Correct Choice ... \n");
            }

        }
    }while(choice!=0);
}

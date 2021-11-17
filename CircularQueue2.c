#include<stdio.h>
#define n 5

int cq[n];
int f,r,count=0;

void insert(int x)
{
    int temp=r;
    if(r==n-1)
    {
        r=0;
    }
    else
    {
        r++;
    }

    if(f==r)
    {
        printf("Overflow");
        count=1;
        r=temp;
        return;
    }
    cq[r]=x;
    if(f==-1)
    {
        f=0;
    }
    return ;
}
int delete()
{
    if(f<0)
    {
        printf("Underflow");
        count=1;
        return;
    }
    int y=cq[f];

    if(f==r)
    {
        f=-1;
        r=-1;
        return y;
    }
    if(f==n-1)
    {
        f=0;
    }
    else
    {
        f++;
    }
    return y;
}
void display()
{
    if(f<0)
    {
        printf("Underflow");
        count=1;
        return;
    }
    for(int i=f;1==1;i++)
    {
        if(i==n)
        {
            i=0;
        }
        if(i<r || i>r)
        {
            printf("%d ",cq[i]);
        }
        if(i==r)
        {
            printf("%d",cq[i]);
            break;
        }

    }
}

void main()
{
    f=-1;
    r=-1;
    printf("1. Insert\n");
    printf("2. Delete \n");
    printf("3. Display \n");
    printf("0. Exit \n");

    int choice,x;

    do
    {
        count=0;
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter a value to insert : ");
                scanf("%d",&x);
                insert(x);
                if(count==0)
                {
                    printf("\nSuccessfully inserted %d\n",x);
                }
                break;
            }
            case 2:
            {
                x=delete();
                if(count==0)
                {
                    printf("\nSuccessfully deleted %d  \n",x);
                }
                break;
            }
            case 3:
            {
                display();
                if(count==0)
                {
                    printf("\nSuccessfully displayed\n");
                }
                break;
            }
            case 0:
            {
                break;
            }
            default :
            {
                printf("\nPlease Enter Correct Value ...\n");
            }
        }

    }while(choice!=0);
}

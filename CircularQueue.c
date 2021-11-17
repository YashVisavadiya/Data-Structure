#include<stdio.h>
#define N 10
struct queue
{
    int CQ[N];
    int F,R;
}q1;
int count,track=0;
int main()
{
    q1.F=-1;
    q1.R=-1;
    printf("1. Insert\n");
    printf("2. Delete \n");
    printf("3. Display \n");
    printf("0. Exit \n");

    int choice,X;

    do
    {
        count=0;
        printf("\nEnter : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1 :
            {
                printf("\nEnter a Value To Insert :");
                scanf("%d",&X);
                INSERT(X);
                if(count==0)
                {
                    printf("Successfully INSERTED %d\n",X);
                }
                break;
            }
            case 2 :
            {
                X=DELETE();
                if(count==0)
                {
                    printf("Successfully DELETED %d\n",X);
                }
                break;
            }
            case 3 :
            {
                DISPLAY();
                if(count==0)
                {
                    printf("\nSuccessfully DISPLAYED\n");
                }
                break;
            }
            case 0 :
            {
                break;
            }
            default :
            {
                printf("Please Enter Correct Value ...");
            }
        }
    }while(choice!=0);

    return 0;
}
void INSERT(int X)
{
    if(q1.R==N-1)
    {
        q1.R=0;
    }else
    {
        q1.R=q1.R+1;
    }
    if(q1.F==q1.R)
    {
        printf("OVERFLOW");
        count++;
        return;
    }
    q1.CQ[q1.R]=X;
    if(q1.F==-1)
    {
        q1.F++;
    }
    track++;
    return ;
}
int DELETE()
{
    int Y;
    if(q1.F==-1)
    {
        printf("UNDERFLOW");
        count++;
        return;
    }
    Y=q1.CQ[q1.F];

    if(q1.F==q1.R)
    {
        q1.F=-1;
        q1.R=-1;
        track--;
        return Y;
    }
    if(q1.F==N-1)
    {
        q1.F=0;
    }
    else
    {
        q1.F=q1.F+1;
    }
    track--;
    return Y;
}
void DISPLAY()
{
    if(q1.F==-1)
    {
        printf("UNDERFLOW");
        count++;
        return ;
    }
    for(int i=q1.F;(i<=q1.R)||(i>q1.R);i++)
    {
        if(i>N-1)
        {
            i=0;
            count++;
        }
        if(count!=1 && ((i>q1.R)||(i<=q1.R)))
        {
            printf("%d ",q1.CQ[i]);
        }
        if(count==1 && i>q1.R)
            break;
    }
    return;
}


#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define n 10

float st[n],value;
int TOP;
char prefix[n];

void PUSH(int x)
{
    if(TOP>=n-1)
    {
        printf("Overflow\n");
        exit(1);
    }
    TOP++;
    st[TOP]=x;

}
float POP()
{
    if(TOP<0)
    {
        printf("Underflow\n");
        exit(1);
    }
    TOP--;

    return st[TOP+1];
}
float perform_operation(float n1,float n2,char ch)
{
    if(ch=='+')
    {
        return (n1+n2);
    }
    else if(ch=='-')
    {
        return (n1-n2);
    }
    else if(ch=='*')
    {
        return (n1*n2);
    }
    else if(ch=='/')
    {
        return (n1/n2);
    }
    else if(ch=='^' || ch == '$')
    {
        return (pow(n1,n2));
    }
}

void main()
{

    TOP=-1;
    value=0;

    int i;
    float n1,n2;

    printf("Enter prefix Expression : ");
    scanf("%s",prefix);
    int length=strlen(prefix);
    char *e;
    e = &prefix[strlen(prefix)-1];
    int num;
    while(length--)
    {
        if(isdigit(*e))
        {
            num =* e - '0';
            PUSH(num);
        }
        else
        {
            n1=POP();
            n2=POP();
            value=perform_operation(n1,n2,*e);

            PUSH(value);
        }
        e--;
    }
    printf("Answer is %.2f",POP());
}


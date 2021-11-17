#include<stdio.h>
#include<conio.h>
#include<math.h>
#define n 10

float st[n],value;
int TOP;
char postfix[n];

void PUSH(int x)
{
    if(TOP>=n-1)
    {
        printf("Overflow\n");
        return;
    }
    TOP++;
    st[TOP]=x;

}
float POP()
{
    if(TOP<0)
    {
        printf("Underflow\n");
        return;
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

    TOP=0;
    value=0;

    int i;
    float n1,n2;

    printf("Enter Postfix Expression : ");
    scanf("%s",postfix);


    char *e;
    e=postfix;
    int num;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num=*e-48;
            PUSH(num);
        }
        else
        {
            n2=POP();
            n1=POP();
            value=perform_operation(n1,n2,*e);

            PUSH(value);
        }
        e++;
    }
    printf("Answer is %.2f",POP());
}

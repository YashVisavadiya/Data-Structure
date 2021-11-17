#include<stdio.h>
#include<string.h>
#define n 20

char s[n],infix[n],postfix[n];
int top,rank;

int G(char s)
{
    if(s == '+' || s == '-')
    return 2;
    else if(s == '*' || s =='/')
        return 4;
    else if(s == '^' || s == '$')
        return 5;
    else if(s == '(' || s == ')')
        return 0;
    else
        return 8;
}
int F(char s)
{
    if(s == '+' || s == '-')
        return 1;
    else if(s == '*' || s =='/')
        return 3;
    else if(s == '^' || s == '$')
        return 6;
    else if(s == '(')
        return 9;
    else if(s == ')')
        return 0;
    else
        return 7;
}
int R(char s)
{
    if(s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '$' )
        return -1;
    else if(s == '(' || s == ')')
        return 0;
    else
        return 1;

}
void PUSH(char x)
{
    if(top>=n-1)
    {
        printf("OVERFLOW");
        return;
    }
    top++;
    s[top]=x;
    return;
}
char POP()
{
    if(top<0)
    {
        printf("UNDERFLOW");
        return;
    }
    top--;
    return s[top+1];
}
void main()
{
    printf("Enter INFIX Expression : ");
    scanf("%s",infix);
    infix[strlen(infix)]=')';
    top=0;
    s[top]='(';
    rank=0;

    int i=0;
    char temp;
    char *e;
    e=infix;
    while(*e!='\0')
    {
        if(top<0)
        {
            printf("INVALID\n");

            return;
        }
        while( G( s[top] ) > F( *e ) )
        {
            temp=POP();
            postfix[i]=temp;
            i++;
            rank=rank+R(temp);
            if(rank<1)
            {
                printf("INVALID\n");

                return;
            }
        }
        if( G(s[top]) != F(*e) )
        {
            PUSH(*e);
        }
        else
        {
            POP();
        }
        e++;
    }
    if(top == -1 && rank == 1)
    {
        printf("VALID\n");
        printf("%s",postfix);
    }
    else
    {
        printf("INVALID\n");
    }
}

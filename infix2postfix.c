#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack [50];
int top= -1;
void push (char x)
{
    stack[++top]=x;
}
int pop()
{
    return(stack [top--]);
}
int prior(char x)
{
    int p;
    if (x=='('||x=='#')p=1;
    if (x=='+'||x=='-')p=2;
    if (x=='*'||x=='/')p=3;
    if (x=='^'||x=='$')p=4;
    return p;
}
void main()
{
    char infix[20],postfix[20];
    int i, j=0;
    printf("Enter The Infix Express :\n");
    gets(infix);
    push('#');
    for(i=0;i<strlen(infix);i++)
    {
        if(isalnum(infix[i]))
        postfix[j++]=infix[i];
        else if (infix[i]=='(')
        push(infix[i]);
        else if(infix[i]==')')
        {
            while (stack[top]!='(')
            postfix[j++]=pop();
            pop ();
        }
        else
        {
            while(prior(stack[top])>=prior(infix[i]))
            postfix[j++]=pop();
            push (infix[i]);
        }
    }
    while(stack[top]!='#')
    postfix[j++]=pop();
    postfix [j]='\0';
    printf("\n Postfix expression is :\n");
    puts(postfix);
}

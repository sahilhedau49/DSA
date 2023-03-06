// Practical 2
// To study and implement Stack ADT and write a function to convert infix expression to postfix expression and 
// evaluate the postfix expression using a Stack.
// Submission Date: 03 Jan 2023

#include <stdio.h>
#include "char_stack.c"
#include "int_stack.c"

void in_to_post(struct stack *s, char infix[], char postfix[]);
int isOperator(char a);
int isParanthesis(char a);
int operator_precedence(char a);
int length_of_string(char str[]);
int power(int a, int b);
int eval_postfix(char postfix[]);
int eval(int c1, int c2, char o);

int main()
{
    struct stack s;
    create(&s);

    char infix[MAXSIZE],postfix[MAXSIZE];
    printf("Enter infix expression: ");
    scanf("%s",&infix);

    in_to_post(&s,infix,postfix);
    printf("\nInfix expression is %s",infix);
    printf("\nPostfix expression is %s\n",postfix);

    float answer = eval_postfix(postfix);
    printf("Evaluation using postfix expression gives (in int): %.2f",answer);

    return 0;
}

void in_to_post(struct stack *s, char infix[], char postfix[])
{
    int n = length_of_string(infix);
    int i,j=0;
    for(i=0;i<n;i++)
    {
        if(isParanthesis(infix[i]) == 0)
        {
            if(isOperator(infix[i]) == 1)
            {
                while( isEmpty(s)==0 && operator_precedence(s->a[s->top]) >= operator_precedence(infix[i]) ){
                    postfix[j]=s->a[s->top];
                    pop(s);
                    j++;
                }                   
                push(s,infix[i]);
            }
            else
            {
                postfix[j] = infix[i];
                j++;
            }
        }
        else
        {
            if(infix[i] == '(')
            push(s,'(');
            else
            {
                while(s->a[s->top] != '('){
                    postfix[j]=s->a[s->top];
                    pop(s);
                    j++;
                }
                pop(s);
            }
        }
    }

    while(isEmpty(s)==0){
        postfix[j]=s->a[s->top];
        pop(s);
        j++;
    }

    postfix[j]='\0';
}

int isOperator(char a)
{
    if(a=='+' ||  a=='-' ||  a=='*' ||  a=='/' ||  a=='^' ||  a=='%')
        return 1;
    else
        return 0;
}

int isParanthesis(char a)
{
    if(a=='(' || a==')')
    return 1;
    else 
    return 0;
}

int operator_precedence(char a)
{
    if(a == '^')
    return 3;
    else if(a=='*' || a=='/' || a=='%')
    return 2;
    else if(a=='+' || a=='-')
    return 1;
    else
    return 0;
}

int length_of_string(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}

int eval_postfix(char postfix[])
{
    struct int_stack os;
    float ans;
    int i,num;
    for(i=0;i<length_of_string(postfix);i++)
    {
        if(isOperator(postfix[i]) == 1)
        {
            int c1,c2;
            c2 = is_pop(&os);
            c1 = is_pop(&os);
            ans = eval(c1,c2,postfix[i]);
            is_push(&os,ans);
        }
        else
        {
            num = postfix[i]-48;
            is_push(&os,num);
        }
    }
    int r = is_pop(&os);
    return r;
}

int eval(int c1, int c2, char o)
{
    int a;
    switch(o)
    {
        case '+':
            a = c1+c2;
            break;

        case '-':
            a = c1-c2;
            break;

        case '*':
            a = c1*c2;
            break;

        case '/':
            a = c1/c2;
            break;

        case '%':
            a = c1%c2;
            break;

        case '^':
            a = power(c1,c2);
            break;

        default:
            printf("Error!\n");
    }
    return a;
}

int power(int a, int b)
{
    int p=1; 
    while(b--)
        p = a*p;
    return p;
}
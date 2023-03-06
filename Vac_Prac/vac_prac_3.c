/*
Design an algorithm and implement a program for parentheses checker using appropriate data structure.

Ex. (()) - Matching parenthesis
((()) - Unmatched parenthesis.

Cover all the possible test cases.
*/

#include<stdio.h>
#define MAXSIZE 20

struct stack{
    char a[MAXSIZE];
    int top;
};

void initialize(struct stack * s);
int parentheses_checker(struct stack *s, char str[], int n);
int push(struct stack *s, char p);
int isEmpty(struct stack *s);
int pop(struct stack *s);

int main()
{
    struct stack s;
    int n;
    printf("Enter number of elements (under 20): ");
    scanf("%d",&n);
    char str[n];
    printf("Enter string: ");
    scanf("%s",&str);
    
    initialize(&s);
    parentheses_checker(&s,str,n);

    return 0;
}

void initialize(struct stack * s)
{
    s->top = -1;
}

int parentheses_checker(struct stack *s, char str[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        char p = str[i];
        if(p == '(')
        {
            push(s,p);
        }
        else if(p == ')')
        {
            int flag = pop(s);
            if(flag == 0)
            {
                printf("__Invalid parentheses__\n");
                return 0;
            }
        }
        else
        {
            printf("Invaild string!");
            return 0;
        }
    }

    if(isEmpty(s) == 1)
    printf("__Valid parentheses__\n");
    else
    printf("__Invalid parentheses__\n");
}

int push(struct stack *s, char p)
{
    (s->top)++;
    s->a[s->top] = p;
}

int pop(struct stack *s)
{
    if(isEmpty(s) == 1)
    {
        return 0;
    }
    else
    {
        (s->top)--;
        return 1;
    }
}

int isEmpty(struct stack *s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}
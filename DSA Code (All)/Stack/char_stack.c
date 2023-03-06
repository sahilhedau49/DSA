#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

struct stack{
	char a[MAXSIZE];
	int top;
};

void create(struct stack * s);
int isFull(struct stack * s);
int isEmpty(struct stack * s);
void push(struct stack * s, char n);
void pop(struct stack * s);
void peek(struct stack s);

void create(struct stack * s)
{
	s->top = -1;
}

int isFull(struct stack * s)
{
	if(s->top == MAXSIZE-1)
		return 1;
	else
		return 0;
}

int isEmpty(struct stack * s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

void push(struct stack * s, char n)
{
	if(isFull(s) == 1)
	{
		printf("Code Terminated! Stack is full.\n");
	}
	else
	{
		(s->top)++;
		s->a[s->top] = n;
	}
}

void pop(struct stack * s)
{
	if(isEmpty(s) == 1)
		printf("Cannot pop element!\n");
	else
		(s->top)--;
}

void peek(struct stack s)
{
	printf("  %c\n",s.a[s.top]);
}
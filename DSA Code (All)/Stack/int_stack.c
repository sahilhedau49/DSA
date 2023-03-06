#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

struct int_stack{
	int a[MAXSIZE];
	int top;
};

void is_create(struct int_stack * s);
int is_isFull(struct int_stack * s);
int is_isEmpty(struct int_stack * s);
void is_push(struct int_stack * s, int n);
int is_pop(struct int_stack * s);
void is_peek(struct int_stack s);

void is_create(struct int_stack * s)
{
	s->top = -1;
}

int is_isFull(struct int_stack * s)
{
	if(s->top == MAXSIZE-1)
		return 1;
	else
		return 0;
}

int is_isEmpty(struct int_stack * s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

void is_push(struct int_stack * s, int n)
{
	if(is_isFull(s) == 1)
	{
		printf("Code Terminated! Stack is full.\n");
	}
	else
	{
		(s->top)++;
		s->a[s->top] = n;
	}
}

int is_pop(struct int_stack * s)
{
	if(is_isEmpty(s) == 1)
	{
		printf("Cannot pop element!\n");
		return -1;
	}
	else
	{
		int data = s->a[s->top];
		(s->top)--;
		return data;
	}
}

void is_peek(struct int_stack s)
{
	printf(" %.2f\n",s.a[s.top]);
}
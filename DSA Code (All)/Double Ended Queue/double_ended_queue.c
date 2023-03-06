#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 20
int limit = 6;
int site_count = 0;

struct double_queue{
	char a[CAPACITY];
	int front;
	int rear;
};

void create(struct double_queue * dq);
int isEmpty(struct double_queue dq);
int isFull(struct double_queue dq);
void insert_from_rear(struct double_queue * dq,char key);
void insert_from_front(struct double_queue * dq,char key);
char delete_from_rear(struct double_queue * dq);
char delete_from_front(struct double_queue * dq);
int is_String(char s[]);
void lowercase(char s[]);
int length_dq(struct double_queue dq);
int is_palindrome(char s[],struct double_queue * dq);
char peek_rear(struct double_queue dq);
char peek_front(struct double_queue dq);
void visit_site(char key, struct double_queue * dq);
char delete_recent_site(struct double_queue * dq);
void display_queue(struct double_queue dq);

int main()
{
    struct double_queue dq;

    int ch;
    char s[20];
    printf("\nEnter 1 for Palindrome Checker.\nEnter 2 to see Browser History.\nEnter 3 to END the program.\n ");
    do{
        printf("\nEnter choice: ");      
        scanf(" %d",&ch);
        switch(ch)
        {
            case 1: printf("Enter string to check: ");
                    scanf("%s",s);
                    create(&dq);
                    is_palindrome(s,&dq);
                    break;
            
            case 2: printf("\n--> Browser History\n");
                    create(&dq);
                    visit_site('1',&dq);
                    visit_site('2',&dq);
                    visit_site('3',&dq);
                    display_queue(dq);
                    delete_recent_site(&dq);
                    display_queue(dq);
                    visit_site('4',&dq);
                    visit_site('5',&dq);
                    visit_site('6',&dq);
                    visit_site('7',&dq);
                    display_queue(dq);
                    visit_site('8',&dq);
                    display_queue(dq);
                    break;
        
            case 3: exit(1);

            default: printf("Invalid Choice!\n");
        }  
    }while(1);

    return 0;
}

void create(struct double_queue * dq)
{
	dq->front = -1;
	dq->rear = -1;
}

int isEmpty(struct double_queue dq)
{
	if(dq.front == -1)
		return 1;
	else
		return 0;
}

int isFull(struct double_queue dq)
{
	if(dq.front == (((dq.rear) + 1) % CAPACITY))
		return 1;
	else
		return 0;
}

void insert_from_rear(struct double_queue * dq,char key)
{
	if(isFull(*dq))
		printf("Queue is Full, Cannot Insert!\n");
	else
    {
        if(isEmpty(*dq))
			dq->front = 0;
		dq->rear = (dq->rear + 1) % CAPACITY;
		dq->a[dq->rear] = key;
	}
}

void insert_from_front(struct double_queue * dq,char key)
{
	if(isFull(*dq))
		printf("Queue is Full, Cannot Insert!\n");
	else
	{
        if(isEmpty(*dq))
        {
			dq->front = 0;
			dq->rear = 0;
		}
		else if(dq->front == 0)
			dq->front = CAPACITY - 1;
		else
			(dq->front)--;
		
		dq->a[dq->front] = key;
	}
}

char delete_from_rear(struct double_queue * dq)
{
	if(isEmpty(*dq))
	{
		printf("Empty Queue, Cannot Delete!\n");
		return '\0';
	}
	else
	{
		char key = dq->a[dq->rear];
		if((dq->rear) == (dq->front))
        {
			dq->rear = -1;
			dq->front = -1;
		}
		else if(dq->rear == 0)
			dq->rear = CAPACITY - 1;
		else
			(dq->rear)--;
			
		return key;
	}
}

char delete_from_front(struct double_queue * dq)
{
	if(isEmpty(*dq))
	{
		printf("Empty Queue, Cannot Delete!\n");
		return '\0';
	}
	else
	{
		char key = dq->a[dq->front];
		if((dq->rear) == (dq->front))
		{
			dq->rear = -1;
			dq->front = -1;
		}
		else
			dq->front = ((dq->front)+1)%CAPACITY;
			
		return key;
	}
}

int is_palindrome(char s[],struct double_queue * dq)
{
    printf("%s --> ",s);
	if(is_String(s))
	{
        lowercase(s);
		for(int i=0;s[i]!='\0';i++)
			insert_from_rear(dq,s[i]);
		
		int flag = 1;
		while(length_dq(*dq)>1 && flag==1)
		{
			char l,f;
			l = delete_from_front(dq);
			f = delete_from_rear(dq);
			if(f != l)
				flag = 0;
		}
		
		if(flag == 1)
			printf("YES! It's a Palindrome\n",s);
		else
			printf("NO! It's not a Palindrome\n",s);
			
		return flag;
    }
	else
        return 0;
}

int is_String(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            i++;
        else
            return 0;
    }
    return 1;
}

void lowercase(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='A' && s[i]<='Z')
            s[i] = s[i] + 32;
        i++;
    }
}

int length_dq(struct double_queue dq)
{
    int len;
    if(isEmpty(dq))
        return 0;
    else
    {
        len = (dq.front > dq.rear) ? (CAPACITY - dq.front + dq.rear + 1) : (dq.rear - dq.front + 1);
        return len;
    }
}

char peek_rear(struct double_queue dq)
{
	if(isEmpty(dq))
    {   
		printf("Cannot Peek(Queue is Empty)\n");
        return '\0';
    }
	else
    {
		printf("%c \n",dq.a[dq.rear]);
        return dq.a[dq.rear];
    }
}

char peek_front(struct double_queue dq)
{
	if(isEmpty(dq))
	{
        printf("Cannot Peek(Queue is Empty)\n");
        return '\0';
    }
	else
    {
		printf("%c \n",dq.a[dq.front]);
		return dq.a[dq.front];
	}
}

void visit_site(char key, struct double_queue * dq)
{
    if(isFull(*dq) || site_count >= limit){
		delete_from_front(dq);
	}
	insert_from_rear(dq,key);
	site_count++;
}

char delete_recent_site(struct double_queue * dq)
{
	char key = delete_from_rear(dq);
	site_count--;
	return key;
}

void display_queue(struct double_queue dq)
{
	if(isEmpty(dq))
		printf("No site is open!\n");
	else
	{
		while(dq.front != (((dq.rear) + 1) % CAPACITY))
        {
			printf("%c  ",dq.a[dq.front]);
			dq.front = (dq.front + 1) % CAPACITY;
		}
   		printf("\n");
	}
}
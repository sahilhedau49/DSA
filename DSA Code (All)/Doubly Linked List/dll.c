#include<stdio.h>
#include<stdlib.h>

struct node * createNode();
void printInfo();
void display(struct node *head);
void print_reverse(struct node * head);
int length_dll(struct node ** head);
void insert_at_end(struct node ** head, int key);
void insert_at_beg(struct node ** head, int key);
void insert_at_pos(struct node ** head, int key, int pos);
int delete_at_end(struct node ** head);
int delete_at_beg(struct node ** head);
int delete_at_pos(struct node **head, int pos);
void sort_dll(struct node ** head);

struct node{
    struct node * prev;
	int data;
	struct node * link;
};

int main()
{
	struct node s;
	struct node * head = NULL;

	int ch,key,p;
	printInfo();

	while(1)
	{
		printf("\nEnter choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("Enter key: ");
					scanf(" %d",&key);
					insert_at_end(&head,key);
					break;
				
			case 2: printf("Enter key: ");
					scanf(" %d",&key);
					insert_at_beg(&head,key);
					break;

			case 3: printf("Enter key and position resp.: ");
					scanf(" %d %d",&key,&p);
					insert_at_pos(&head,key,p);
					break;

			case 4: delete_at_end(&head);
					break;

			case 5: delete_at_beg(&head);
					break;

			case 6: printf("Enter position to delete: ");
					scanf(" %d",&p);
					delete_at_pos(&head,p);
					break;

			case 7: printf("DLL is\n");
					display(head);
					break;

			case 8: printf("DLL in reverse order is\n");
					print_reverse(head);
					printf("\n");
					break;

			case 9: sort_dll(&head);
					printf("Sorted DLL is\n");
					display(head);
					break;

			case 10: exit(1);
					 break;
			
			default: printf("Invalid Case!\n");
		}
	}

	return 0;
}

struct node * createNode()
{
	struct node * newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
	printf("Node is not created.\n");
	else
	printf("Node is created\n"); 
	
	return newNode;
}

void printInfo()
{
	printf("Enter 1 for inserting at end.\nEnter 2 for inserting at beginning.\nEnter 3 for inserting at specific position.\nEnter 4 for deleting at end.\nEnter 5 for deleting at beginning.\nEnter 6 for deleting at specific position.\nEnter 7 to display DLL.\nEnter 8 to display DLL in reverse.\nEnter 9 to sort the DLL.\nEnter 10 to END the program.\n");
}

void display(struct node *head)
{
	if(head == NULL)
		printf("Empty DLL.");
	else
	{
		struct node *temp = head;
		while(temp != NULL)
		{
			printf("->%d",temp->data);
			temp = temp->link;
		}
	}
	printf("\n");
}

void print_reverse(struct node * head)
{
	struct node * temp = head;
	while(temp->link!=NULL)
		temp = temp->link;

	do{
		printf("->%d",temp->data);
		temp = temp->prev;
	}while(temp!=NULL);
}

int length_dll(struct node ** head)
{
	int count = 0;
	struct node * temp = * head;
	while(temp!=NULL){
		count++;
		temp = temp->link;
	}
	return count;
}

void insert_at_end(struct node ** head, int key)
{
	struct node * temp = * head;
	struct node * newNode = createNode();

	newNode->prev = NULL;
	newNode->data = key;
	newNode->link = NULL;

	if(*head == NULL)
		*head = newNode;
	else
	{
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = newNode;
		newNode->prev = temp;
	}
}

void insert_at_beg(struct node ** head, int key)
{
	struct node * temp =  * head;
	struct node * newNode = createNode();

	newNode->prev = NULL;
	newNode->data = key;
	newNode->link = NULL;

	if(*head == NULL)
		*head = newNode;
	else
	{
		temp->prev = newNode;
		*head = newNode;
		newNode->link = temp;
	}
}

void insert_at_pos(struct node ** head, int key, int pos)
{
	struct node * temp = * head;
	struct node * newNode = createNode();

	newNode->prev = NULL;
	newNode->data = key;
	newNode->link = NULL;

	if( pos<1 || pos>length_dll(head) )
		printf("Invalid Postion!\n");
	else
	{
		if(head == NULL)
			* head = newNode;
		else if(pos == 1)
		{
			(*head)->prev = newNode;
			newNode->link = *head;
			*head = newNode;
		}
		else
		{
			int index=1;
			while(index != pos-1){
				temp = temp->link;
				index++;
			}
			temp->link->prev = newNode;
			newNode->link = temp->link;
			newNode->prev = temp;
			temp->link = newNode;
		}
	}
}

int delete_at_end(struct node ** head)
{
	struct node * temp = * head;
	int key;

	while(temp->link->link != NULL)
	{
		temp = temp->link;
	}
	key = temp->link->data;
	free(temp->link);
	temp->link = NULL;
	printf("Deletion is done.\n");
	return key;
}

int delete_at_beg(struct node ** head)
{
	struct node *temp = *head;
	int key;

	*head = temp->link;
	(*head)->prev = NULL;
	key = temp->data;
	free(temp);
	printf("Deletion is done.\n");
	return key;
}

int delete_at_pos(struct node **head, int pos)
{
	int len = length_dll(head);
	if (pos < 1 || pos > len)
	{
		printf("Invalid Postion!\n");
		return -1;
	}
	else
	{
		int key;
		struct node *temp = *head;
		if (head == NULL)
			printf("Empty DLL!");
		else if (pos == 1)
		{
			*head = temp->link;
			temp->link->prev = NULL;
			key = temp->data;
			free(temp);
			printf("Deletion is done.\n");
			return key;
		}
		else
		{
			int index = 1;
			while (index != pos - 1)
			{
				temp = temp->link;
				index++;
			}
			struct node* temp1;
			temp1=temp->link;
			key = temp->link->data;
			temp->link = temp->link->link;
			temp->link->prev = temp;
			printf("Deletion is done.\n");
			free(temp1);
		}
		return key;
	}
}

void sort_dll(struct node ** head)
{
	struct node * temp = * head;
	int t;
	while(temp->link!=NULL)
	{
		struct node * temp1 = temp->link;
		while(temp1!=NULL)
		{
			if((temp1->data) < (temp->data))
			{
				t = temp->data;
				temp->data = temp1->data;
				temp1->data = t;
			}
			temp1 = temp1->link;
		}
		temp = temp->link;
	}
}
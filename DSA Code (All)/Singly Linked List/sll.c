#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * link;
};

struct node * createNode();
void printInfo();
void insertatEnd(struct node ** head, int key);
void insertatBeg(struct node ** head, int key);
void insertAtPos(struct node **head, int key, int pos);
int delete_at_end(struct node ** head);
int delete_at_beg(struct node ** head);
int deleteAtPos(struct node **head, int pos);
void display(struct node *head);
int length_sll(struct node ** head);
int search(struct node *head, int key);
void reverse_sll(struct node **head);
void update(struct node **head, int ele, int key);

int main()
{
	// struct node s;
	struct node * head = NULL;

	int ch;
	printInfo();

	while(1)
	{
		int k,p,l,ser;
		printf("\nEnter choice: ");
		scanf(" %d",&ch);
		
		switch(ch){
			case 1: printf("Enter key:\n");
					scanf(" %d",&k);
					insertatEnd(&head,k);
					break;

			case 2: printf("Enter key:\n");
					scanf(" %d",&k);
					insertatBeg(&head,k);
					break;

			case 3: printf("Enter key and position resp.:\n");
					scanf(" %d %d",&k,&p);
					insertAtPos(&head,k,p);
					break;

			case 4: delete_at_end(&head);
					break;

			case 5: delete_at_beg(&head);
					break;

			case 6: printf("Enter position to delete:\n");
					scanf(" %d",&p);
					deleteAtPos(&head,p);
					break;

			case 7: printf("SLL is\n");
					display(head);
					printf("\n");
					break;

			case 8: l = length_sll(&head);
					printf("Length of SLL is %d.\n",l);
					break;

			case 9: printf("Enter the key for seraching:\n");
					scanf(" %d",&k);
					ser = search(head,k);
					if(ser == -1)
						printf("Key not found.\n");
					else
						printf("%d is found at %d position.\n",k,ser);
					break;

			case 10: reverse_sll(&head);
					printf("SLL after reversing:\n");
					display(head);
					printf("\n");
					break;

			case 11: printf("Enter the numbers a and b (to update b of SLL to a):\n");
					int ele;
					scanf(" %d %d",&ele,&k);
					update(&head,ele,k);
					break;

			case 12: exit(1);
					break;

			default: printf("Invalid choice!\n");
					break;
		}
	}

	return 0;
}

struct node * createNode()
{
	struct node * newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
	printf("Allocation Failed.\n");
	else
	printf("Node is created\n"); 
	
	return newNode;
}

void printInfo()
{
	printf("Enter 1 for inserting at end.\nEnter 2 for inserting at beginning.\nEnter 3 for inserting at specific position.\nEnter 4 for deleting at end.\nEnter 5 for deleting at beginning.\nEnter 6 for deleting at specific position.\nEnter 7 to display SLL.\nEnter 8 for having length of SLL.\nEnter 9 for seraching any key in SLL.\nEnter 10 for reversing SLL.\nEnter 11 for updating SLL.\nEnter 12 to END the program.\n");
}

void insertatEnd(struct node ** head, int key)
{
	struct node * temp = * head;
	struct node *newNode = createNode();
	
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
	}
}

void display(struct node *head)
{
	if(head == NULL)
		printf("Empty SLL.");
	else
	{
		struct node *temp = head;
		while(temp != NULL)
		{
			printf("->%d",temp->data);
			temp = temp->link;
		}
	}
}

void insertatBeg(struct node ** head, int key)
{
	struct node *newNode = createNode();
	newNode->data = key;
	newNode->link = *head;
	*head = newNode;
}

int length_sll(struct node ** head)
{
	int count = 0;
	struct node * temp = * head;
	while(temp!=NULL){
		count++;
		temp = temp->link;
	}
	return count;
}

int delete_at_end(struct node ** head)
{
	int key;
	struct node *temp = *head;
	if (*head == NULL)
		printf("Empty SLL.");
	else if (temp->link == NULL)
	{
		key = temp->data;
		*head = NULL;
		free(temp);
	}
	else
	{
		while(temp->link->link != NULL)
		{
			temp = temp->link;
		}
		key = temp->link->data;
		free(temp->link);
		temp->link = NULL;
	}
	return key;
}

int delete_at_beg(struct node ** head)
{
	if(head == NULL)
		printf("Empty SLL.");
	else
	{
		int key;
		struct node *temp = *head;
		*head = temp->link;
		key = temp->data;
		free(temp);
		return key;
	}
}

void insertAtPos(struct node **head, int key, int pos)
{
	int len = length_sll(head);
	if (pos < 1 || pos > len)
		printf("Invalid Postion!\n");
	else
	{
		struct node *newNode = createNode();
		newNode->data = key;
		newNode->link = NULL;
		struct node *temp;
		if (*head == NULL)
			*head = newNode;
		else if (pos == 1)
		{
			newNode->link = *head;
			*head = newNode;
		}
		else
		{
			temp = *head;
			int index = 1;
			while (index != pos - 1)
			{
				temp = temp->link;
				index++;
			}
			newNode->link = temp->link;
			temp->link = newNode;
		}
	}
}

int deleteAtPos(struct node **head, int pos)
{
	int len = length_sll(head);
	if (pos < 1 || pos > len)
	{
		printf("Invalid Postion!\n");
		return -1;
	}
	else
	{
		int key;
		struct node *temp;
		if (head == NULL)
			printf("Empty SLL!");
		else if (pos == 1)
		{
			temp = *head;
			*head = temp->link;
			key = temp->data;
			free(temp);
		}
		else
		{
			temp = *head;
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
			free(temp1);
		}
		return key;
	}
}

int search(struct node *head, int key)
{
	if (head == NULL)
	{
		printf("Searching is failed \n");
		return -1;
	}
	else
	{
		struct node *temp;
		temp = head;
		int index = 0;
		while (temp != NULL)
		{
			index++;
			if (key == temp->data)
				return index;
			temp = temp->link;
		}
		return -1;
	}
}

void update(struct node **head, int ele, int key)
{
	if (head == NULL)
		printf("Empty SLL.\n");
	else
	{
		struct node *temp;
		temp = *head;
		while (temp != NULL)
		{
			if (key == temp->data)
			{
				temp->data = ele;
				break;
			}
			temp = temp->link;
		}
	}
}

void reverse_sll(struct node **head)
{
	struct node *prev, *curr, *next;
	curr = *head;
	prev = NULL;
	while(curr!=NULL){
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

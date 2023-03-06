/*
Suppose there are two singly linked lists both of which intersect at some point and
become a single linked list. The head or start pointers of both the lists are known, but
the intersecting node is not known. Also, the number of nodes in each of the lists
before they intersect is unknown and may be different in each list. List1 may have n
nodes before it reaches the intersection point, and List2 might have m nodes before it
reaches the intersection point where m and n may be m = n,m < n or m > n. Give an
algorithm for finding the merging point.
*/

#include<stdio.h>
#include "sll.c"

void joinSLL(struct node **head, struct node **headright);
int find_intersection(struct node **head1, struct node **head2);

int main()
{
    struct node s1,s2,s3;
	struct node * head1 = NULL;
    struct node * head2 = NULL;
	struct node * headright = NULL;

    insertatEnd(&head1,1);
    insertatEnd(&head1,2);
    insertatEnd(&head1,3);
    insertatEnd(&head1,4);

    insertatEnd(&head2,10);
    insertatEnd(&head2,20);

    insertatEnd(&headright,100);
    insertatEnd(&headright,200);
    insertatEnd(&headright,300);

    joinSLL(&head1,&headright);
    joinSLL(&head2,&headright);

    printf("SLL 1 :  ");
    display(head1);
    printf("\nSLL 2 :  ");
    display(head2);

    find_intersection(&head1,&head2);

    return 0;
}

void joinSLL(struct node **head, struct node **headright)
{
    struct node *temp = *head;
    while(temp->link!=NULL){
		temp = temp->link;
	}
    temp->link = *headright;
}

int find_intersection(struct node **head1, struct node **head2)
{
    struct node *temp1 = *head1;

    int i=1;
    while(temp1!=NULL)
    {
        struct node *temp2 = *head2;
        int j=1;
        while(temp2!=NULL)
        {
            if(temp1 == temp2)
            {
                printf("\n\nThis is intersection node.\n");
                printf("Index of this node w.r.t sll 1 is %d.\n",i);
                printf("Index of this node w.r.t sll 2 is %d.\n",j);
                printf("Data at this node is %d.\n\n",temp1->data);
                return 0;
            }
            temp2 = temp2->link;
            j++;
        }
        temp1 = temp1->link;
        i++;
    }
    return 1;
}
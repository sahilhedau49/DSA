#include <stdio.h>
#define CAPACITY 10
int a[CAPACITY];

struct queue{
  int rear;
  int front;
};

int isFull(struct queue queue1, struct queue queue2);
int isEmpty(struct queue queue12);
void create(struct queue *queue1, struct queue *queue2);
void insertq1(struct queue *queue1, struct queue *queue2, int key);
void insertq2(struct queue *queue1, struct queue *queue2, int key);
int peek(struct queue queue12);
int deleteq1(struct queue *queue1);
int deleteq2(struct queue *queue2);

int main()
{
  struct queue queue1;
  struct queue queue2;
  create(&queue1, &queue2);
  deleteq1(&queue1);
  deleteq2(&queue2);
  insertq1(&queue1, &queue2, 7);
  insertq1(&queue1, &queue2, 14);
  insertq1(&queue1, &queue2, 4);
  deleteq1(&queue1);
  insertq1(&queue1, &queue2, 11);
  peek(queue1);
  deleteq1(&queue1);
  peek(queue1);
  insertq2(&queue1, &queue2, 6);
  insertq2(&queue1, &queue2, 3);
  insertq2(&queue1, &queue2, 47);
  insertq2(&queue1, &queue2, 8);
  peek(queue2);
  insertq2(&queue1, &queue2, 17);
  deleteq2(&queue2);
  peek(queue2);
  insertq2(&queue1, &queue2, 21);
  peek(queue2);
  return 0;
}

int isFull(struct queue queue1, struct queue queue2)
{
  if ((queue1.rear == CAPACITY - 1) || (queue2.rear == 0) || (queue1.rear == queue2.rear))
  {
    printf("Array is full (overflow)!\n");
    return 1;
  }
  else
  return 0;
}

int isEmpty(struct queue queue12)
{
  if (queue12.rear == queue12.front)
  {
    printf("Queue is Empty (underflow)!\n");
    return 1;
  }
  else
  return 0;
}

void create(struct queue *queue1, struct queue *queue2)
{
  queue1->rear = 0;
  queue1->front = 0;
  queue2->rear = CAPACITY - 1;
  queue2->front = CAPACITY - 1;
  printf("Queues are created!\n");
}

void insertq1(struct queue *queue1, struct queue *queue2, int key)
{
  if (isFull(*queue1, *queue2))
  {
    printf("Cannot insert!\n");
  }
  else
  {
    a[queue1->rear] = key;
    queue1->rear++;
  }
}

void insertq2(struct queue *queue1, struct queue *queue2, int key)
{
  if (isFull(*queue1, *queue2))
  {
    printf("Cannot insert!\n");
  }
  else
  {
    a[queue2->rear] = key;
    queue2->rear--;
  }
}

int peek(struct queue queue12)
{
  printf("The front element of queue -->  %d \n", a[queue12.front]);
  return a[queue12.front];
}

int deleteq1(struct queue *queue1)
{
  if (isEmpty(*queue1))
  {
    printf("Cannot Delete the element in Queue1\n");
    return -1;
  }
  else
  {
    int key = a[queue1->front];
    (queue1->front)++;
    return key;
  }
}

int deleteq2(struct queue *queue2)
{
  if (isEmpty(*queue2))
  {
    printf("Cannot Delete the element in Queue2\n");
    return -1;
  }
  else
  {
    int key = a[queue2->front];
    (queue2->front)--;
    return key;
  }
}


#include<stdio.h>
#include<stdlib.h>

#define NULL 0


// *Use Double linked list //
typedef struct node 
{
  int data;
  struct node *next;
} l;

l *head = NULL;
l *tail = NULL; 

void enqueue_rear(int x)
{
  l *newnode = (l *)malloc(sizeof(l));
  newnode->data = x;
  newnode->next = NULL;

  if(head == NULL)
  {
    head = tail = newnode;
  }

  else
  {
    tail->next = newnode;
    tail = newnode;
  }
}

void dequeue_front()
{
  if(head == NULL )
  {
    printf("\nThe queue is empty \n");
  }

  else
  {
    l *temp = head;

    head = head->next;

    free(temp);
  }
}


void enqueue_front(int x)
{
  l *newnode = (l *)malloc(sizeof(l));

  newnode->data = x;
  newnode->next = NULL;

  newnode->next = head;
  head = newnode;
}

void dequeue_rear()
{
  if(head == NULL)
  {
    printf("\nThe queue is empty\n");
  }

  else if(head->next == NULL) // Only one node, in this case we need to make head = NULL and tail = NULL
  {
    l *temp = head;
    free(temp);
    head = NULL;
    tail = NULL;
  }

  else
  {
    l *temp = head; // Initialisze temp with head ... Temp will start from head and move till last node
    l *prevnode;

    while(temp->next != NULL)
    {
      prevnode = temp;
      temp = temp->next;
    }

    prevnode->next = NULL;
    tail = prevnode;
    free(temp);
  }
}

void display()
{
  if(head == NULL)
  {
    printf("\nQueue is empty\n");
  }

  else
  {
    l *temp = head;

    while(temp != NULL)
    {
      printf(" %d", temp->data);
      temp = temp->next;
    }

    printf("\n");
  }
}

void front()
{
  if(head == NULL)
  {
    printf("\nQueue is empty\n");
  }

  else
  {
    printf("\nFront is : %d", head->data);
  }
}

void rear()
{
  if(head == NULL)
  {
    printf("\nQueue is empty\n");
  }

  else
  {
    printf("\nRear is : %d", tail->data);
  }
}


int main()
{
  enqueue_rear(3);
  enqueue_rear(4);
  enqueue_rear(5);
  enqueue_front(6);
  enqueue_front(7);

  display();

  dequeue_front();
  display();

  dequeue_rear();

  display();

  front();
  rear();
}
#include<stdio.h>
#include<stdlib.h>

#define NULL 0

typedef struct node
{
  int data;
  struct node *next;
} l;

l *head = NULL;
l *tail = NULL;

void enqueue(int x)
{
  l *newnode = (l *)malloc(sizeof(l));

  newnode->data = x;

  newnode->next = NULL;
  

  if(head == NULL) //Queue is empty -> if queue is empty head will be NULL 
  {
    head = tail = newnode;
  }

  else // Queue is not empty so move the tail along with newnode to the end
  {
    tail->next = newnode;
    tail = newnode;
  }
}


void dequeue()
{
  if(head == NULL) // Queue is empty
  {
    printf("\nQueue is empty \n");
  }
  else
  {
    l *temp = head; 
    printf("\nPopped value is : %d\n ", head->data);
    head = head->next; // Popping the frist value i.e front value
    free(temp);
  }
}

void front()
{
  if(head == NULL) // Queue is empty
  {
    printf("\nQueue is empty \n");
  }

  else
  {
    printf("\nFront element is : %d", head->data);
  }
}

void display()
{
  if(head == NULL)
  {
    printf("\nQueue is empty \n");
  }

  else
  {
    l *temp = head;

    while(temp != NULL)
    {
      printf(" %d ", temp->data);
      temp = temp->next;
    }
  }
}

int main()
{
  enqueue(3);
  enqueue(4);
  enqueue(5);
  display();
  dequeue();
  front();
}
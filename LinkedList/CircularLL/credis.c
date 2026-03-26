#include<stdio.h>
#include<stdlib.h>
#define NULL 0

typedef struct node
{
  int data;
  struct node *next;
} l;

l *head = NULL;
l *temp;

void create(l *);
void display(l *);

int main()
{
  l *head = (l *)malloc(sizeof(l));
  l *temp = (l *)malloc(sizeof(l));
  printf("\nCreating a list : \n");
  create(head);
  printf("\nDisplaying a list : \n");
  display(head);
}

void create(l *ptr)
{
  
  printf("\nEnter data of current node : \n");
  scanf("%d", &ptr->data);
  ptr->next = NULL;

  if(head == 0)
  {
    head = temp = ptr;
  }

  else
  {
    temp->next = ptr;
    temp = ptr;
  }

  temp->next = head;
  char ch = 'y';
  printf("\nDo you want to continue?(y/n) : \n");
  scanf(" %c", &ch);

  if(ch == 'y' || ch== 'Y')
  {
    ptr->next = (l *)malloc(sizeof(l));
    ptr = ptr->next;
    create(ptr);
  }
}

void display(l *ptr)
{
  l *temp = (l *)malloc(sizeof(l));
  temp = head;
  while(temp->next != head)
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("%d->", temp->data);
}


#include<stdio.h>
#include<stdlib.h>
#define NULL 0

typedef struct node 
{
  int data;
  struct node *next;
} l;

l *head = NULL;
void create(l *);
void display(l *);
void push(l *);

int main()
{
  head = (l *)malloc(sizeof(l));
  printf("\nCreating list : \n");
  create(head);
  printf("\nDisplaying list : \n");
  display(head);
  printf("\nPushing node into stack\n");
  push(head);
  printf("\nDisplaying new list : \n");
  display(head);
}

void create(l *ptr)
{
  printf("\nEnter data of the current node : ");
  scanf("%d", &ptr->data);
  ptr->next = NULL;

  char ch = 'y';
  printf("\nDo you want to continue?(y/n) : ");
  scanf(" %c", &ch);

  if(ch == 'y' || ch == 'Y')
  {
    ptr->next = (l *)malloc(sizeof(l));
    ptr = ptr->next;
    create(ptr);
    }
}

void display(l *ptr)
{
  printf("\nDisplaying the list : ");
  while(ptr != NULL)
  {
    printf("%d->", ptr->data);
    ptr = ptr->next;
  }
  printf("NULL");
}

void push(l *ptr)
{
  l *newnode = (l *)malloc(sizeof(l));
  printf("\nEnter data of the newnode : \n");
  scanf("%d", &newnode->data);

  while(ptr->next != NULL)
  {
    ptr = ptr->next;
  }

  newnode->next = ptr->next;
  ptr->next = newnode;
}
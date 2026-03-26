#include<stdio.h>
#include<stdlib.h>
#define NULL 0

typedef struct node 
{
  int data;
  struct node *next;
  struct node *prev;
}l;
l *head = NULL;
void create(l *);
void display(l *);
void delbeg(l *);

int main()
{
  head = (l *)malloc(sizeof(l));
  printf("\nCreating a list : \n");
  create(head);
  printf("\nDisplaying a list : \n");
  display(head);
  printf("\nDeleting at the beginning : \n");
  delbeg(head);
  printf("\nDisplaying the new list : \n");
  display(head);
}

void create(l *ptr)
{
  printf("Enter data of current node : ");
  scanf("%d", &ptr->data);
  ptr->next = NULL;
  ptr->prev = NULL;

  char ch = 'y';
  printf("Do you want to continue?(y/n) : ");
  scanf(" %c", &ch);

  if(ch == 'y' || ch == 'Y')
  {
    ptr->next = (l *)malloc(sizeof(l));
    ptr = ptr->next;
    return (create(ptr));
  }
}

void display(l *ptr)
{
  while(ptr != NULL)
  {
    printf("%d->", ptr->data);
    ptr = ptr->next;
  }
  printf("NULL");
}

void delbeg(l *ptr)
{
  l *temp = (l *)malloc(sizeof(l));
  temp = head;
  head = head->next;
  free(temp);
}
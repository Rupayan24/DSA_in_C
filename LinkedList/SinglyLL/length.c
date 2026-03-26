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
void length(l *);
int main()
{
  head = (l*)malloc(sizeof(l));
  printf("\nCreating the list : \n");
  create(head);
  printf("\nDisplaying a list : \n");
  display(head);
  printf("\nLength of list : \n");
  length(head);
  printf("\nDisplaying new list : \n");
  display(head);
}

void create(l* ptr)
{
  char ch = 'y';
  
  printf("Enter data of the current node : ");
  scanf("%d", &ptr->data);
  ptr->next = NULL;

  
  printf("Do you want to continue?(y/n) : ");
  scanf(" %c", &ch);
  if(ch == 'y' || ch == 'Y')
  {
    ptr->next = (l*)malloc(sizeof(l));
    ptr = ptr->next;
    (create(ptr));
  }
}

void display(l* ptr)
{
  while(ptr != NULL)
  {
    printf("%d->", ptr->data);
    ptr = ptr->next;
  }
  printf("NULL");
}

void length(l* ptr)
{
  int count = 0;
  while(ptr != NULL)
  {
    count++;
    ptr = ptr->next;
  }
  printf("\nLength of LL is : %d", count);
}

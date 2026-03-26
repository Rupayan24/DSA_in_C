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
void delmid(l *);
int main()
{
  head = (l*)malloc(sizeof(l));
  printf("\nCreating the list : \n");
  create(head);
  printf("\nDisplaying a list : \n");
  display(head);
  printf("\nDeleting at the middle : \n");
  delmid(head);
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

void delmid(l * ptr)
{
  l* temp = (l* )malloc(sizeof(l));
  l* nextnode = (l* )malloc(sizeof(l));
  int pos,i;
  printf("\nEnter pos to be deleted : \n");
  scanf("%d", &pos);
  temp = head;
  if(i<pos-1)
  {
    temp = temp->next;
    i++;
  }
  nextnode = temp->next;
  temp->next = nextnode->next;
  free(nextnode);
}
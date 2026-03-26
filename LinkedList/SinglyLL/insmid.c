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
void insmid(l *);
int main()
{
  head = (l*)malloc(sizeof(l));
  printf("\nCreating the list : \n");
  create(head);
  printf("\nDisplaying a list : \n");
  display(head);
  printf("\nInserting at the middle : \n");
  insmid(head);
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

void insmid(l * ptr)
{
  l *newnode = (l *)malloc(sizeof(l));
  printf("\nEnter newnode data : ");
  scanf("%d", &newnode->data);

  int ele;
  printf("\nEnter element after which you want to insert: \n");
  scanf("%d", &ele);

  while(ptr->next != NULL)
  {
    if(ptr->data == ele)
    {
      newnode->next = ptr->next;
      ptr->next = newnode;
    }
    ptr = ptr->next;
  }

  
}
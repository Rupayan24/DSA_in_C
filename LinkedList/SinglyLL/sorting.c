//NOT WORKING
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
void sorting(l *);
void swap(l *, l *);
int main()
{
  head = (l*)malloc(sizeof(l));
  printf("\nCreating the list : \n");
  create(head);
  printf("\nDisplaying a list : \n");
  display(head);
  printf("\nSorting the linked list : \n");
  sorting(head);
  swap(l* ,l*);
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

void sorting(l* ptr1)
{
  l *temp = (l *)malloc(sizeof(l));
  l *ptr2 = (l *)malloc(sizeof(l));
  while(ptr1 != NULL)
  {
    ptr2 = ptr1->next;
    while(ptr1 != NULL)
    {
    if(ptr1->data > ptr2->data)
    {
      swap(ptr1->data,ptr2->data);
    }
    ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next;
  }
}

void swap(l *ptr1,l *ptr2)
{
  
  if(ptr1->data > ptr2->data)
  {
    int temp = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data = temp;
  }
}
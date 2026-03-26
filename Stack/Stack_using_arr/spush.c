#include<stdio.h>
#include<stdlib.h>

int n;
int top = -1;

void create_s(int *);
void display_s(int *);
void push(int *);

int main()
{
  printf("\nEnter no of elements : ");
  scanf("%d", &n);
  int a[n];

  create_s(a);
  display_s(a);
  push(a);
}

void create_s(int *ptr)
{
  int count;
  printf("\nEnter the number of elements you want to enter : ");
  scanf("%d", &count);

  for (int i = 0; i < count; i++)
  {
    printf("\nEnter elements : \n");
    scanf("%d", &ptr[++top]);
  }
}

void display_s(int *ptr)
{
  printf("\n Displaying the array : \n");
  for (int i = 0; i <= top; i++)
  {
    printf("%d ", ptr[i]);
  }
}

void push(int *ptr)
{
  if(top == n-1)
  {
    printf("\nOverflow\n");
  }
  else
  {
  int x;
  printf("\nEnter element you want to emter in stack : ");
  scanf("%d", &x);

  printf("\nPushing element into stack : ");
  top++;
  ptr[top] == x;
  printf("%d is pushed into stack",x);
  }




}


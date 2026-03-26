#include<stdio.h>
#include<stdlib.h>

int f = -1;
int r = -1;

void enqueue_rear(int x, int arr[], int n)
{
  if(r == n - 1)
  {
    printf("\nOverflow\n");
  }

  else if(f == -1 && r == -1)
  {
    f = r = 0;
    arr[r] = x;
  }

  else
  {
    r++;
    arr[r] = x;
  }
}

void dequeue_front(int arr[], int n)
{
  if(f == -1)
  {
    printf("\nUnderflow\n");
  }

  else if(f == r) // Single element 
  {
    f = r = -1;
  }

  else
  {
    f = f + 1;
  }
}

void enqueue_front(int x, int arr[], int n)
{
  
}

int main()
{
  int n;
  printf("\nEnter the size of array : \n");
  scanf(" %d", &n);

  int arr[n];
}

#include<stdio.h>
#include<stdlib.h>

int f = 0;
int r = -1;

void enqueue(int x,int arr[], int n, int *curr_size) // *curr_size is used for derefencing and moving curr_size value by reference
{
  if((*curr_size) == n)
  {
    printf("\nOverflow\n");
  }

  else
  {
    r = (r + 1) % n;
    arr[r] = x;
    (*curr_size)++;
  }
}

void dequeue(int arr[], int n, int *curr_size)
{
  if((*curr_size) == 0)
  {
    printf("\nUnderflow\n");
  }

  else
  {
    f = (f + 1) % n;
    (*curr_size)--;
  }
}

void front(int arr[], int n, int *curr_size)
{
  if((*curr_size) == 0)
  {
    printf("\nUnderflow\n");
  }

  else
  {
    printf("\n %d is the front\n", arr[f]);
  }
}

void display(int arr[], int n, int *curr_size)
{
  if((*curr_size) == 0)
  {
    printf("\nUnderflow\n");
  }

  else
  {
    int i = f; // Initailize with f
    while(i != r)
    {
      printf(" %d ", arr[i]);
      i = (i + 1) % n;
    }

    printf(" %d \n", arr[r]); // print r
  }
}

int main()
{
  int n;
  printf("\nEnter size : \n");
  scanf(" %d", &n);

  int arr[n];
  int curr_size = 0;

  enqueue(1, arr, n, &curr_size); // & is used with curr_size
  enqueue(2, arr, n, &curr_size);
  enqueue(3, arr, n, &curr_size);
  display(arr, n, &curr_size);
  dequeue(arr, n, &curr_size);
  enqueue(4, arr, n, &curr_size);

  display(arr, n, &curr_size);
  dequeue(arr, n, &curr_size);
  display(arr, n, &curr_size);
  front(arr, n, &curr_size);
}



/*

#include<stdio.h>
#include<stdlib.h>

int f = -1;
int r = -1;

void enqueue(int x,int arr[], int n, int curr_size)
{
  if((r + 1) % n == f)
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
    r = (r + 1) % n;
    arr[r] = x;
    
  }
}

void dequeue(int arr[], int n, int curr_size)
{
  if(f == -1 && r == -1)
  {
    printf("\nUnderflow\n");
  }

  else
  {
    f = (f + 1) % n;
  }
}

void front(int arr[], int n, int curr_size)
{
  if(f == -1 && r == -1)
  {
    printf("\nUnderflow\n");
  }

  else
  {
    printf(" %d is the front", arr[f]);
  }
}

void display(int arr[], int n, int curr_size)
{
  if(f == -1 && r == -1)
  {
    printf("\nUnderflow\n");
  }

  else
  {
    int i;
    while(i != r)
    {
      printf(" %d ", arr[i]);
    }

    printf(" %d ", arr[r]);
  }
}

int main()
{
  int n;
  printf("\nEnter size : ");
  scanf(" %d", &n);

  int arr[n];
  int curr_size;

  enqueue(5, arr, n, curr_size);
  enqueue(4, arr, n, curr_size);
  enqueue(3, arr, n, curr_size);
  enqueue(2, arr, n, curr_size);

  display(arr, n, curr_size);
  dequeue(arr, n, curr_size);
  display(arr, n, curr_size);
  front(arr, n, curr_size);
}

*/
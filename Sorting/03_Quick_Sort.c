#include<stdio.h>

void print(int arr[], int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

int partition(int arr[], int si, int ei)
{
  int pivot = arr[ei];
  int i = -1;

  for (int j = 0; j < ei; j++)
  {
    if(arr[j] < pivot)
    {
      i++;

      int temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
    }
  }

  i++;
  int temp = arr[ei];
  arr[ei] = arr[i];
  arr[i] = temp;

  return i;
}

void quick_sort(int arr[], int si, int ei)
{
  if(si >= ei)
  {
    return;
  }

  int pivot = partition(arr, si, ei);
  quick_sort(arr, si, pivot - 1);
  quick_sort(arr, pivot + 1, ei);
}


int main()
{
  int n;
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int si = 0;
  int ei = n - 1;

  print(arr, n);
  quick_sort(arr, si, ei);
  print(arr, n);

  return 0;
}
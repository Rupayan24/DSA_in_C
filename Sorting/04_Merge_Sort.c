#include<stdio.h>

void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

void merge(int arr[], int si, int mid, int ei)
{
  int size = ei - si + 1;

  int temp[size];

  int i = si;
  int j = mid + 1;
  int k = 0;

  while(i <= mid && j <= ei)
  {
    if(arr[i] <= arr[j])
    {
      temp[k] = arr[i];
      i++;
    }

    else
    {
      temp[k] = arr[j];
      j++;
    }

    k++;
  }

  while(i <= mid)
  {
    temp[k] = arr[i];
    i++;
    k++;
  }

  while(j <= ei)
  {
    temp[k] = arr[j];
    j++;
    k++;
  }

  for (int x = si, y = 0; x <= ei; x++)
  {
    arr[x] = temp[y];
    y++;
  }
}

void merge_sort(int arr[], int si, int ei)
{
  if(si >= ei)
  {
    return;
  }

  int mid = si + (ei - si) / 2;

  merge_sort(arr, si, mid);
  merge_sort(arr, mid + 1, ei);
  merge(arr, si, mid, ei);
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
  merge_sort(arr, si, ei);
  print(arr, n);
}
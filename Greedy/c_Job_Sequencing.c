#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void merge(int low, int mid, int high, int n, int id[], int deadline[], int profit[])
{
  int temp_id[n];
  int temp_deadline[n];
  int temp_profit[n];

  int i = low;
  int j = mid + 1;
  int k = low;

  while(i <= mid && j <= high)
  {
    if(profit[i] >= profit[j])
    {
      temp_id[k] = id[i];
      temp_deadline[k] = deadline[i];
      temp_profit[k] = profit[i];
      i++;
      k++;
    }

    else
    {
      temp_id[k] = id[j];
      temp_deadline[k] = deadline[j];
      temp_profit[k] = profit[j];
      j++;
      k++;
    }
  }

  while(i <= mid)
  {
    temp_id[k] = id[i];
    temp_deadline[k] = deadline[i];
    temp_profit[k] = profit[i];
    i++;
    k++;
  }

  while(j <= high)
  {
    temp_id[k] = id[j];
    temp_deadline[k] = deadline[j];
    temp_profit[k] = profit[j];
    j++;
    k++;
  }

  for (int x = low; x <= high; x++)
  {
    id[x] = temp_id[x];
    deadline[x] = temp_deadline[x];
    profit[x] = temp_profit[x];
  }
}

void merge_sort(int low, int high, int n, int id[], int deadline[], int profit[])
{
  if(low >= high)
  {
    return;
  }
  int mid = low + (high - low) / 2;

  merge_sort(low, mid, n, id, deadline, profit);
  merge_sort(mid + 1, high, n, id, deadline, profit);
  merge(low, mid, high, n, id, deadline, profit);
}

void job_sequencing(int n, int id[], int deadline[], int profit[])
{
  merge_sort(0, n - 1, n, id, deadline, profit);


  // finding out maximum deadline
  int max_deadline = 0;

  for (int i = 0; i < n; i++)
  {
    if(deadline[i] > max_deadline)
    {
      max_deadline = deadline[i];
    }
  }

  int slot[max_deadline + 1];
  bool slot_filled[max_deadline + 1];

  int count_jobs = 0;
  int max_profit = 0;

  for (int i = 0; i < max_deadline + 1; i++)
  {
    slot_filled[i] = false; // making all slots empty
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = deadline[i]; j > 0; j--)
    {
      if(!slot_filled[j]) // i.e. slot is empty
      {
        slot[j] = id[i];
        count_jobs++;
        max_profit += profit[i];
        slot_filled[j] = true;
        break;
      }
    }
  }

  for (int i = 1; i < max_deadline + 1; i++)
  {
    if(slot_filled[i]) // slot is booked
    {
      printf("%d\n", slot[i]);
    }
  }

  printf("%d\n", count_jobs);
  printf("%d\n", max_profit);
}

int main()
{
  int n;
  printf("Enter number of jobs : \n");
  scanf("%d", &n);

  int id[n];
  int deadline[n];
  int profit[n];

  for (int i = 0; i < n; i++)
  {
    id[i] = i + 1;
    printf("Enter deadline of current id\n");
    scanf("%d", &deadline[i]);
    printf("Enter profit of current id\n");
    scanf("%d", &profit[i]);
  }

  job_sequencing(n, id, deadline, profit);
  return 0;
}
#include<stdio.h>
#include<stdlib.h>
// TC - O(NLOGN)
// SC - O(N)

// If the ratios are already sorted in descending order then we donot need to perfom the sort step---> directly do the knapsack loop i.e. --> O(n)

void merge(int low, int mid, int high, int n, float ratio[], float value[], float weight[])
{
  float temp_ratio[n];
  float temp_value[n];
  float temp_weight[n];

  int i = low;
  int j = mid + 1;
  int k = low;

  while(i <= mid && j <= high)
  {
    if(ratio[i] >= ratio[j])
    {
      temp_ratio[k] = ratio[i];
      temp_value[k] = value[i];
      temp_weight[k] = weight[i];
      i++;
      k++;
    }

    else
    {
      temp_ratio[k] = ratio[j];
      temp_value[k] = value[j];
      temp_weight[k] = weight[j];
      j++;
      k++;
    }
  }

  while(i <= mid)
  {
    temp_ratio[k] = ratio[i];
    temp_value[k] = value[i];
    temp_weight[k] = weight[i];
    i++;
    k++;
  }

  while(j <= high)
  {
    temp_ratio[k] = ratio[j];
    temp_value[k] = value[j];
    temp_weight[k] = weight[j];
    j++;
    k++;
  }

  for (int x = low; x <= high; x++)
  {
    ratio[x] = temp_ratio[x];
    value[x] = temp_value[x];
    weight[x] = temp_weight[x];
  }
}

void merge_sort(int low, int high, int n, float ratio[], float value[], float weight[])
{
  if(low >= high)
  {
    return;
  }
  int mid = low + (high - low) / 2;
  merge_sort(low, mid, n, ratio, value, weight);
  merge_sort(mid + 1, high, n, ratio, value, weight);
  merge(low, mid, high, n, ratio, value, weight);
}

float fractional_knapsack(int n, float value[], float weight[], float capacity)
{
  float ratio[n];

  for (int i = 0; i < n; i++)
  {
    ratio[i] = (value[i] / weight[i]);
  }

  merge_sort(0, n - 1, n, ratio, value, weight);

  float max_value = 0;
  

  for (int i = 0; i < n; i++)
  {
    if(weight[i] <= capacity)
    {
      max_value += value[i];
      capacity -= weight[i];
    }

    else
    {
      float res = ratio[i] * capacity;
      max_value += res;
      capacity = 0;
      break;
    }
  }

  return max_value;
}

int main()
{
  int n;
  printf("Enter number of items : \n");
  scanf("%d", &n);

  float value[n];
  printf("Enter value of each item : \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &value[i]);
  }

  float weight[n];
  printf("Enter weight of each item : \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &weight[i]);
  }

  float capacity;
  printf("Enter capacity of the knapsack : \n");
  scanf("%f", &capacity);

  float max_output = fractional_knapsack(n , value, weight, capacity);
  printf("Maximum value is : %f", max_output);
  return 0;
}
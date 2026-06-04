#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void print(int n, char board[n][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%c", board[i][j]);
    }

    printf("\n");
  }

  printf("\n-------------\n");
}


bool isSafe(int n, char board[n][n], int row, int col)
{
  // horizontal
  for (int j = 0; j < n; j++)
  {
    if(board[row][j] == 'Q')
    {
      return false;
    }
  }


  // vertical
  for (int i = 0; i < row; i++)
  {
    if(board[i][col] == 'Q')
    {
      return false;
    }
  }

  // diagonal-left
  for (int i = row,j = col; i >= 0 && j >= 0; i--, j--)
  {
    if(board[i][j] == 'Q')
    {
      return false;
    }
  }

  // diagonal-right
  for (int i = row, j = col; i >= 0 && j < n; i--, j++)
  {
    if(board[i][j] == 'Q')
    {
      return false;
    }
  }

  return true;
}


void solve(int n, char board[n][n], int row)
{
  if(row == n)
  {
    print(n, board);
    return;
  }

  for (int j = 0; j < n; j++)
  {
    if(isSafe(n, board, row, j))
    {
      board[row][j] = 'Q';
      solve(n, board, row + 1);
      board[row][j] = '.'; // backtrack
    }
  }
}

int main()
{
  int n;
  printf("Enter size of board : \n");
  scanf("%d", &n);

  char board[n][n];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      board[i][j] = '.';
    }
  }

  solve(n, board, 0);
  return 0;
}
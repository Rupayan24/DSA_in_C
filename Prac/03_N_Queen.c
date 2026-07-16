#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


// TC - O(N!)
// SC - O(N)
void print(int n, char board[][n], int row)
{
    printf("\n\n");
    int i, j;
    for(i = 0; i < n; i++)
    {

        for(j = 0; j < n; j++)
        {
            printf(" %c", board[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");
}


bool isSafe(int n, char board[][n], int row, int col)
{

    // Row

    int x;

    for(x = 0; x < n; x++)
    {
        if(board[x][col] == 'Q')
        {
            return false;
        }
    }

    // Col
    int y;
    for(y = 0; y < n; y++)
    {
        if(board[row][y] == 'Q')
        {
            return false;
        }
    }

    // Diagonal-left

    int a, b;

    for(a = row, b = col; a>= 0 && b >= 0; a--, b--)
    {

        if(board[a][b] == 'Q')
        {
            return false;
        }
    }


    // Diagonal-right

    int c, d;

    for(c = row, d = col; c >= 0 && d < n; c--, d++)
    {
        if(board[c][d] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void solve(int n, char board[][n], int row)
{

    if(row == n)
    {

        print(n, board, row);
        return;
    }

    int j;
    for(j = 0; j < n; j++)
    {
        if(isSafe(n, board, row, j))
        {
            board[row][j] = 'Q';
            solve(n, board, row+1);
            board[row][j] = '.'; // Backtrack
        }
    }
}

int main()
{
    int n;
    printf("\nEnter number of rows : \n");
    scanf("%d", &n);


    char board[n][n];

    int i,j;

    for(i = 0; i < n; i++)
    {

        for(j = 0; j < n; j++)
        {

            board[i][j] = '.';
        }
    }

    solve(n, board, 0);
    return 0;
}

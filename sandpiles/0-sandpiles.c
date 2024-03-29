#include "sandpiles.h"
#include <stdio.h>

static void print_grid(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", grid[i][j]);
            if (j < 2)
                printf(" ");
        }
        printf("\n");
    }
}

static void topple(int grid[3][3], int row, int col)
{
    grid[row][col] -= 4;
    if (row - 1 >= 0)
        grid[row - 1][col]++;
    if (row + 1 < 3)
        grid[row + 1][col]++;
    if (col - 1 >= 0)
        grid[row][col - 1]++;
    if (col + 1 < 3)
        grid[row][col + 1]++;
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    int stable;
    do
    {
        stable = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    stable = 0;
                    printf("=\n");
                    print_grid(grid1);
                    topple(grid1, i, j);
                }
            }
        }
    } while (!stable);
}

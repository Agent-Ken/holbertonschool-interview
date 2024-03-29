#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * topple - Perform toppling operation at given position
 * @grid: The grid to perform toppling on
 * @row: Row index of the position
 * @col: Column index of the position
 */
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

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: The first sandpile
 * @grid2: The second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int stable = 0;

    // Add the values of corresponding cells
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    while (!stable)
    {
        stable = 1;
        // Check if any cell has more than 3 grains
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    stable = 0;
                    printf("=\n");
                    print_grid(grid1);
                    // Perform toppling operation
                    topple(grid1, i, j);
                }
            }
        }
    }
}

#include <stdio.h>
#include "sandpiles.h"

static void print_grid(int grid[3][3]);
static int is_stable(int grid[3][3]);
static void topple(int grid[3][3], int row, int col);

/**
 * print_grid - Prints a 3x3 grid of integers.
 * @grid: The grid to print.
 */
static void print_grid(int grid[3][3])
{
    int row, col;

    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            if (col)
                printf(" ");
            printf("%d", grid[row][col]);
        }
        printf("\n");
    }
}

/**
 * is_stable - Checks if a grid is stable.
 * @grid: The grid to check.
 *
 * Return: 1 if grid stable, otherwise 0.
 */
static int is_stable(int grid[3][3])
{
    int row, col;

    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            if (grid[row][col] > 3)
                return (0);
        }
    }
    return (1);
}

/**
 * topple - Topples a grid cell and distributes grains.
 * @grid: The grid to topple.
 * @row: The row of the cell to topple.
 * @col: The column of the cell to topple.
 */
static void topple(int grid[3][3], int row, int col)
{
    int i, j;

    grid[row][col] -= 4;
    for (i = row - 1; i <= row + 1; i++)
    {
        for (j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && i < 3 && j >= 0 && j < 3 && !(i == row && j == col))
                grid[i][j]++;
        }
    }
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles.
 * @grid1: The first sandpile.
 * @grid2: The second one.
 *
 * Description: Sums 2 sandpiles and stabilizes the result.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int row, col;

    printf("=\n");
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            grid1[row][col] += grid2[row][col];
        }
    }

    while (!is_stable(grid1))
    {
        print_grid(grid1);
        printf("=\n");
        for (row = 0; row < 3; row++)
        {
            for (col = 0; col < 3; col++)
            {
                if (grid1[row][col] > 3)
                    topple(grid1, row, col);
            }
        }
    }
}

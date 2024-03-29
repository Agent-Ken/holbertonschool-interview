#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Print a 3x3 grid
 * @grid: 3x3 grid to be printed
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
 * topple - Topple a cell in the sandpile
 * @grid: 3x3 grid
 * @row: Row of the cell to be toppled
 * @col: Column of the cell to be toppled
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
 * add_grids - Add two grids element-wise
 * @grid1: 3x3 grid to store the sum
 * @grid2: 3x3 grid to be added to grid1
 */
static void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * mark_unstable - Mark unstable cells in the grid
 * @grid: 3x3 grid to be checked
 * @unstable: 3x3 grid to store unstable cell markers
 *
 * Return: 1 if the grid is unstable, 0 otherwise
 */
static int mark_unstable(int grid[3][3], int unstable[3][3])
{
	int i, j, unstable_found = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				unstable_found = 1;
				unstable[i][j] = 1;
			}
			else
			{
				unstable[i][j] = 0;
			}
		}
	}

	return unstable_found;
}

/**
 * topple_unstable - Topple all unstable cells in the grid
 * @grid: 3x3 grid to be toppled
 * @unstable: 3x3 grid with unstable cell markers
 */
void topple_unstable(int grid[3][3], int unstable[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (unstable[i][j])
			{
				topple(grid, i, j);
				unstable[i][j] = 0;
			}
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: 3x3 grid representing the first sandpile
 * @grid2: 3x3 grid representing the second sandpile
 *
 * Description: The function computes the sum of two sandpiles and stabilizes
 * the resulting sandpile by performing toppling operations as needed.
 * The final stable sandpile is stored in grid1.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable[3][3];

	add_grids(grid1, grid2);

	while (mark_unstable(grid1, unstable))
	{
		printf("=\n");
		print_grid(grid1);
		topple_unstable(grid1, unstable);
	}
}
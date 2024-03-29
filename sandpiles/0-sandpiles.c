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
	int i, j, unstable_found;
	int unstable[3][3];

	/* Add the values of corresponding cells */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (1)
	{
		unstable_found = 0;
		/* Mark unstable cells */
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					unstable_found = 1;
					unstable[i][j] = 1;
				}
				else
					unstable[i][j] = 0;
			}

		if (!unstable_found)
			break;

		printf("=\n");
		print_grid(grid1);

		/* Topple unstable cells */
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (unstable[i][j])
					topple(grid1, i, j, unstable);
	}
}

/**
 * topple - Topple a cell in the sandpile
 * @grid: 3x3 grid
 * @row: Row of the cell to be toppled
 * @col: Column of the cell to be toppled
 * @unstable: 3x3 grid with unstable cell markers
 */
static void topple(int grid[3][3], int row, int col, int unstable[3][3])
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
	unstable[row][col] = 0;
}

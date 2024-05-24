#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_block_empty - Checks if a block should be empty
 * @row: The row index of the block
 * @col: The column index of the block
 * Return: 1 if the block should be empty, 0 otherwise
 */
int is_block_empty(int row, int col)
{
    while (row > 0 || col > 0)
    {
        if (row % 3 == 1 && col % 3 == 1)
            return (1);
        row /= 3, col /= 3;
    }
    return (0);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
    int size = pow(3, level);
    int row, col;

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (is_block_empty(row, col))
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}

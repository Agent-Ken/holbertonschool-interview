#include "slide_line.h"

/**
 * slide_left - Slides and merges an array of integers to the left.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void slide_left(int *line, size_t size)
{
    size_t i, j, last_merged = 0;

    for (i = 0; i < size; i++)
    {
        if (line[i] == 0)
            continue;
        
        if (last_merged > 0 && line[last_merged - 1] == line[i])
        {
            line[last_merged - 1] *= 2;
            line[i] = 0;
            last_merged--;
        }
        else
        {
            if (last_merged != i)
            {
                line[last_merged] = line[i];
                line[i] = 0;
            }
            last_merged++;
        }
    }
}

/**
 * slide_right - Same as above but now to the right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void slide_right(int *line, size_t size)
{
    size_t i, j, last_merged = size;

    for (i = size; i > 0; i--)
    {
        if (line[i - 1] == 0)
            continue;
        
        if (last_merged < size && line[last_merged] == line[i - 1])
        {
            line[last_merged] *= 2;
            line[i - 1] = 0;
            last_merged++;
        }
        else
        {
            if (last_merged != i)
            {
                line[last_merged - 1] = line[i - 1];
                line[i - 1] = 0;
            }
            last_merged--;
        }
    }
}

/**
 * slide_line - Slides and merges an array of integers in the given direction.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 * 
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);

    return (1);
}

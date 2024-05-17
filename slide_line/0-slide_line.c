#include "slide_line.h"

/**
 * slide_left - Slides an array of integers to the left.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void slide_left(int *line, size_t size)
{
    size_t i = 0, j = 0;

    while (i < size)
    {
        if (line[i] != 0)
        {
            line[j] = line[i];
            if (i != j)
                line[i] = 0;
            j++;
        }
        i++;
    }
}

/**
 * slide_right - Slides an array of integers to the right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void slide_right(int *line, size_t size)
{
    size_t i = size - 1, j = size - 1;

    while (i > 0)
    {
        if (line[i] != 0)
        {
            line[j] = line[i];
            if (i != j)
                line[i] = 0;
            j--;
        }
        i--;
    }
}

/**
 * merge_line - Merges an array of integers.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to merge (SLIDE_LEFT or SLIDE_RIGHT).
 */
void merge_line(int *line, size_t size, int direction)
{
    size_t i, merge_index = (direction == SLIDE_LEFT) ? 0 : size - 1;
    int last_num = -1;

    for (i = (direction == SLIDE_LEFT) ? 0 : size - 1;
         (direction == SLIDE_LEFT) ? (i < size) : (i != (size_t)-1);
         (direction == SLIDE_LEFT) ? i++ : i--)
    {
        if (line[i] == 0)
            continue;

        if (line[i] == last_num)
        {
            line[merge_index] += line[i];
            line[i] = 0;
            last_num = -1;
            merge_index += (direction == SLIDE_LEFT) ? 1 : -1;
        }
        else
        {
            if (last_num != -1)
                merge_index += (direction == SLIDE_LEFT) ? 1 : -1;

            last_num = line[i];
            if (merge_index != i)
            {
                line[merge_index] = line[i];
                line[i] = 0;
            }
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

    merge_line(line, size, direction);

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);

    return (1);
}

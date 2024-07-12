#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the array being searched
 * @array: Pointer to the first element of the array to search in
 * @left: Left index of the array to print
 * @right: Right index of the array to print
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        if (i > left)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Recursive function
 * @array: Pointer to the first element of the array to search in
 * @left: Left index of the subarray to search in
 * @right: Right index of the subarray to search in
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if value is not present
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);

    mid = left + (right - left) / 2;

    if (array[mid] == value && (mid == left || array[mid - 1] != value))
        return (mid);

    if (array[mid] >= value)
        return (advanced_binary_recursive(array, left, mid, value));
    return (advanced_binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if value is not present
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}

#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Turns a subtree into a max heap.
 * @array: The array representing the heap.
 * @size: Size of the array.
 * @root: Root index of the subtree.
 * @end: End index of the heap.
 */
void heapify(int *array, size_t size, size_t root, size_t end)
{
	size_t max = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < end && array[left] > array[max])
		max = left;

	if (right < end && array[right] > array[max])
		max = right;

	if (max != root)
	{
		swap(&array[root], &array[max]);
		print_array(array, size);
		heapify(array, size, max, end);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size; i > 1; i--)
	{
		swap(&array[0], &array[i - 1]);
		print_array(array, size);
		heapify(array, size, 0, i - 1);
	}
}

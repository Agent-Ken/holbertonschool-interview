#include "binary_trees.h"

/**
 * heap_size - Function that calculates the size of a heap
 * @root: pointer to the root node of the Heap
 * Return: heap size
 */
int heap_size(heap_t *root)
{
	int left, right;

	if (root == NULL)
		return (0);
	left = heap_size(root->left);
	right = heap_size(root->right);
	return (left + right + 1);
}

/**
 * insert_level_order - Function that inserts a node into a Max Binary Heap
 * @root: Pointer to the root node of the Heap
 * @idx: current index in heap
 * @size: size of the heap
 * @value: The value store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *insert_level_order(heap_t *root, int idx, int size, int value)
{
	heap_t *left, *right;

	if (root == NULL)
		return (NULL);
	if (idx == size / 2)
	{
		if (root->left == NULL)
		{
			root->left = binary_tree_node(root, value);
			return (root->left);
		}
		root->right = binary_tree_node(root, value);
		return (root->right);
	}
	left = insert_level_order(root->left, (2 * idx), size, value);
	right = insert_level_order(root->right, (2 * idx + 1), size, value);
	if (left)
		return (left);
	return (right);
}

/**
 * swap - Function that swaps two integers
 * @a: pointer to a int
 * @b: pointer to another int
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * heap_insert - Function that inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	int new_size;

	if (*root == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*root = new_node;
		return (new_node);
	}
	new_size = heap_size(*root) + 1;
	new_node = insert_level_order(*root, 1, new_size, value);
	for (; new_node->parent; new_node = new_node->parent)
	{
		if (new_node->parent->n < new_node->n)
			swap(&new_node->parent->n, &new_node->n);
		else
			break;
	}
	return (new_node);
}
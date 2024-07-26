#include "binary_trees.h"

/**
 * tree_height - CHeck the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	left_height = tree->left ? 1 + tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + tree_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * tree_heapsort - binary tree Heapsort
 * @temporary: pointer to the heap root
 * Return: pointer to last node
 */

heap_t *tree_heapsort(heap_t *temporary)
{
	int aux;

	while (temporary->left || temporary->right)
	{
		if (!temporary->right || temporary->left->n > temporary->right->n)
		{
			aux = temporary->n;
			temporary->n = temporary->left->n;
			temporary->left->n = aux;
			temporary = temporary->left;
		}
		else if (!temporary->left || temporary->left->n < temporary->right->n)
		{
			aux = temporary->n;
			temporary->n = temporary->right->n;
			temporary->right->n = aux;
			temporary = temporary->right;
		}
	}
	return (temporary);
}

/**
 * tree_preorder - goes through a binary tree using pre-order traversal
 * @root: pointer root of the tree
 * @node: pointer node in the tree
 * @h: height of tree
 * @l: layer on the tree
 */
void tree_preorder(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;
	if (h == l)
		*node = root;
	l++;
	if (root->left)
		tree_preorder(root->left, node, h, l);
	if (root->right)
		tree_preorder(root->right, node, h, l);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 */

int heap_extract(heap_t **root)
{
	int value;
	heap_t *aux, *node;

	if (!root || !*root)
		return (0);
	aux = *root;
	value = aux->n;
	if (!aux->left && !aux->right)
	{
		*root = NULL;
		free(aux);
		return (value);
	}
	tree_preorder(aux, &node, tree_height(aux), 0);
	aux = tree_heapsort(aux);
	aux->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}

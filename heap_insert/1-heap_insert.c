#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @value: value to be inserted
 * @root: tree root
 * Return: pointer to the created node, or NULL on failure.
 */

void correct_heap(heap_t **root) {
    if ((*root)->left != NULL && (*root)->right != NULL) {
        correct_heap(&(*root)->left);
        correct_heap(&(*root)->right);
    }
    else if ((*root)->left != NULL && (*root)->left->left != NULL && (*root)->left->right == NULL) {
        if ((*root)->left->n > (*root)->left->left->n) {
            (*root)->right = (*root)->left;
            (*root)->right->parent = *root;
            (*root)->left = (*root)->left->left;
            (*root)->left->parent = *root;
            (*root)->right->left = NULL;
        } else {
            (*root)->right = (*root)->left->left;
            (*root)->right->parent = *root;
            (*root)->left->left = NULL;
        }
    } else if ((*root)->right != NULL && (*root)->left == NULL && (*root)->right->left != NULL) {
        if ((*root)->right->n < (*root)->right->left->n) {
            (*root)->left = (*root)->right;
            (*root)->left->parent = *root;
            (*root)->right = (*root)->right->left;
            (*root)->right->parent = *root;
            (*root)->right->left = NULL;
        } else {
            (*root)->left = (*root)->right->left;
            (*root)->left->parent = *root;
            (*root)->right->left = NULL;
        }
    } else if ((*root)->right == NULL && (*root)->left != NULL && (*root)->left->right != NULL) {
        (*root)->right = (*root)->left->right;
        (*root)->right->parent = *root;
        (*root)->left->right = NULL;
        correct_heap(&(*root));
    }
}

int height(heap_t *root) {
    int left, right;

    if (root == NULL) {
        return (0);
    }

    left = height(root->left);
    right = height(root->right);

    if (left > right) {
        return (left + 1);
    } else {
        return (right + 1);
    }
}

int left_is_full(heap_t *root, int h) {
    int count = 0;

    if (root == NULL) {
        root = root->left;
    }

    while (root->left != NULL && root->right != NULL) {
        count++;
        root = root->left;
    }

    if (count == h - 1) {
        return (1);
    } else {
        return (0);
    }
}

int right_is_full(heap_t *root, int h) {
    int count = 0;

    if (root == NULL) {
        root = root->right;
    }

    while (root->left != NULL && root->right != NULL) {
        count++;
        root = root->right;
    }

    if (count == h - 1) {
        return (1);
    } else {
        return (0);
    }
}

heap_t *heap_insert(heap_t **root, int value) {
    heap_t *newNode, *tmp;
    int left_is_ful, right_is_ful;

    if (*root == NULL) {
        *root = malloc(sizeof(heap_t));
        if (*root == NULL) {
            return NULL;
        }
        (*root)->n = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->parent = NULL;
        return *root;
    }

    if ((*root)->n > value && (*root)->left == NULL)
    {
        newNode = malloc(sizeof(binary_tree_t));

        if (newNode == NULL)
        {
        return (NULL);
        }

        newNode->n = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = *root;
        (*root)->left = newNode;
        return (newNode);
    }
    else if ((*root)->n > value && (*root)->right == NULL)
    {
        newNode = malloc(sizeof(binary_tree_t));

        if (newNode == NULL)
        {
        return (NULL);
        }

        newNode->n = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = *root;
        (*root)->right = newNode;
        return (newNode);
    }
    else if (((*root)->n < value)) {
        newNode = malloc(sizeof(binary_tree_t));

        if (newNode == NULL)
        {
        return (NULL);
        }

        newNode->n = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;

        left_is_ful = left_is_full(*root, height(*root));
        right_is_ful = right_is_full(*root, height(*root));
        if ((left_is_ful == 1 && right_is_ful == 1) || (left_is_ful == 0 && right_is_ful == 1) || (left_is_ful == 0 && right_is_ful == 0)) {
            if ((*root)->parent == NULL && (*root)->left != NULL) {
                newNode->parent = (*root)->parent;
                newNode->right = (*root)->right;
                newNode->left = (*root);
                (*root)->right = NULL;
                *root = newNode;
                (*root)->right->parent = newNode;
                (*root)->left->parent = newNode;
            } else {
                newNode->parent = (*root)->parent;
                newNode->left = *root;
                (*root)->parent = newNode;
                *root = newNode;
            }
        }
        else if (left_is_ful == 1 && right_is_ful == 0) {
            if ((*root)->parent == NULL && (*root)->right != NULL) {
                newNode->parent = (*root)->parent;
                newNode->left = (*root)->left;
                newNode->right = (*root);
                (*root)->left = NULL;
                *root = newNode;
                (*root)->right->parent = newNode;
                (*root)->left->parent = newNode;
            } else {
                newNode->parent = (*root)->parent;
                newNode->right = *root;
                (*root)->parent = newNode;
                *root = newNode;
            }
        }

        correct_heap(root);
        return (newNode);
    } 

    left_is_ful = left_is_full(*root, height(*root));
    right_is_ful = right_is_full(*root, height(*root));
    if ((left_is_ful == 1 && right_is_ful == 1) || (left_is_ful == 0 && right_is_ful == 1) || (left_is_ful == 0 && right_is_ful == 0)) {
        heap_insert(&(*root)->left, value);
    } else {
        heap_insert(&(*root)->right, value);
    }

    tmp = malloc(sizeof(heap_t));
    tmp->n = value;
    return (tmp);
}
#include "binary_trees.h"

heap_t *get_last_node(heap_t *root);
void heapify_down(heap_t *node);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 if the function fails
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node, *new_root;

    if (root == NULL || *root == NULL)
        return (0);

    value = (*root)->n;

    last_node = get_last_node(*root);
    if (last_node == *root)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    new_root = last_node;
    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    new_root->left = (*root)->left;
    if (new_root->left)
        new_root->left->parent = new_root;
    new_root->right = (*root)->right;
    if (new_root->right)
        new_root->right->parent = new_root;

    free(*root);
    *root = new_root;

    heapify_down(*root);

    return (value);
}

/**
 * get_last_node - Gets the last node in level-order
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    heap_t *last = NULL;
    queue_t *queue = NULL;

    if (!root)
        return (NULL);

    queue = create_queue();
    if (!queue)
        return (NULL);

    enqueue(&queue, root);
    while (queue != NULL)
    {
        last = dequeue(&queue);
        if (last->left)
            enqueue(&queue, last->left);
        if (last->right)
            enqueue(&queue, last->right);
    }

    free_queue(queue);
    return (last);
}

/**
 * heapify_down - Maintains heap property by shifting the node down
 * @node: Pointer to the node to heapify down
 */
void heapify_down(heap_t *node)
{
    heap_t *largest = node;
    int temp;

    while (1)
    {
        if (node->left && node->left->n > largest->n)
            largest = node->left;
        if (node->right && node->right->n > largest->n)
            largest = node->right;
        if (largest == node)
            break;

        temp = node->n;
        node->n = largest->n;
        largest->n = temp;

        node = largest;
    }
}

/**
 * create_queue - Creates a queue
 *
 * Return: Pointer to the newly created queue
 */
queue_t *create_queue(void)
{
    return (NULL);
}

/**
 * enqueue - Adds a node to the queue
 * @queue: Double pointer to the queue
 * @node: Pointer to the node to add
 *
 * Return: 0 on success, 1 on failure
 */
int enqueue(queue_t **queue, heap_t *node)
{
    queue_t *new_node, *temp;

    new_node = malloc(sizeof(queue_t));
    if (!new_node)
        return (1);

    new_node->node = node;
    new_node->next = NULL;

    if (*queue == NULL)
    {
        *queue = new_node;
    }
    else
    {
        temp = *queue;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }

    return (0);
}

/**
 * dequeue - Removes a node from the queue
 * @queue: Double pointer to the queue
 *
 * Return: Pointer to the removed node
 */
heap_t *dequeue(queue_t **queue)
{
    queue_t *temp;
    heap_t *node;

    if (*queue == NULL)
        return (NULL);

    temp = *queue;
    *queue = (*queue)->next;
    node = temp->node;
    free(temp);

    return (node);
}

/**
 * free_queue - Frees the queue
 * @queue: Pointer to the queue to free
 */
void free_queue(queue_t *queue)
{
    queue_t *temp;

    while (queue)
    {
        temp = queue;
        queue = queue->next;
        free(temp);
    }
}

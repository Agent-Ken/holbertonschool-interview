#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/**
 * struct queue_s - Queue node
 *
 * @node: Pointer to the heap node
 * @next: Pointer to the next queue node
 */
struct queue_s
{
    heap_t *node;
    struct queue_s *next;
};

typedef struct queue_s queue_t;

heap_t *get_last_node(heap_t *root);
void heapify_down(heap_t *node);
queue_t *create_queue(void);
int enqueue(queue_t **queue, heap_t *node);
heap_t *dequeue(queue_t **queue);
void free_queue(queue_t *queue);

int heap_extract(heap_t **root);

#endif
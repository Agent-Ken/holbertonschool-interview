#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express = NULL, *prev = NULL;

    if (!list)
        return (NULL);

    express = list->express;
    prev = list;

    while (express)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        if (express->n >= value)
            break;
        prev = express;
        express = express->express;
    }

    if (!express)
    {
        for (express = prev; express->next; express = express->next)
            ;
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
            prev->index, express->index);

    for (; prev && prev->index <= express->index; prev = prev->next)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
    }

    return (NULL);
}

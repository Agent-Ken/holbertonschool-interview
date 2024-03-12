#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number) {
    listint_t *newNode;
    listint_t *current;

    current = *head;

    newNode = malloc(sizeof(listint_t));
    if (newNode == NULL){
        return (NULL);
    }
    newNode->n = number;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        if (current->n > number) {
            newNode->next = current;
            *head = newNode;
            return (newNode);
        }

        while (current->next != NULL && current->next->n < number)
            current = current->next;
        

        if (current->next == NULL) {
            newNode->next = NULL;
            current->next = newNode;
            return (newNode);
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
    return (newNode);
}

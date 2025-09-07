/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

/* Function to insert node at the rear (end) */
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    // Create new node
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
        return FAILURE; // Memory allocation failed

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*head == NULL) // Empty list
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }

    return SUCCESS;
}

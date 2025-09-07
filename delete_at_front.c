/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

void delete_at_front(Dlist **head, Dlist **tail)
{
    if (!*head)
        return;

    Dlist *temp = *head;
    *head = (*head)->next;

    if (*head)
        (*head)->prev = NULL;
    else
        *tail = NULL; // List became empty

    free(temp);
}

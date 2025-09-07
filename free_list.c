/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

/* Function to free a doubly linked list */
void free_list(Dlist **head, Dlist **tail)
{
    Dlist *current = *head;
    Dlist *nextNode;

    while (current)
    {
        nextNode = current->next; // Store next node
        free(current);            // Free current node
        current = nextNode;       // Move to next node
    }

    // Reset head and tail pointers
    *head = NULL;
    *tail = NULL;
}

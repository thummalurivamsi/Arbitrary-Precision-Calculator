/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

/* Function to insert a digit at the front of the doubly linked list */
int insert_at_front(Dlist **head, Dlist **tail, int digit)
{
  Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));
  if (!newNode)
    return FAILURE;

  newNode->data = digit;
  newNode->prev = NULL;
  newNode->next = *head;

  if (*head)
    (*head)->prev = newNode;
  *head = newNode;

  if (!*tail)
    *tail = newNode; // list was empty

  return SUCCESS;
}

/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

/* Function to print a number stored in a doubly linked list */
void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("0\n"); // Empty list represents 0
        return;
    }

    Dlist *temp = head;

    // Traverse from head to tail, printing each digit
    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    // printf("\n"); // Newline after printing the number
}

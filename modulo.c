/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

int modulo(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
  /*
  // If divisor is 0, modulo is undefined
  if ((*head2)->next == NULL && (*head2)->data == 0)
  {
    printf("Error: Division by zero in modulo operation\n");
    return FAILURE;
  }
    */

  // If dividend < divisor → remainder = dividend itself
  if (compare_list(head1, head2) < 0)
  {
    copy_list(*head1, *tail1, headR, tailR);
    return SUCCESS;
  }

  // Temporary list to store subtraction result
  Dlist *tempHead = NULL, *tempTail = NULL;

  // Repeat subtraction until dividend < divisor
  while (compare_list(head1, head2) >= 0)
  {
    // Subtract divisor from dividend, store in temp list
    subtraction(head1, tail1, head2, tail2, &tempHead, &tempTail);

    // Free old dividend
    free_list(head1, tail1);

    // Update dividend with subtraction result
    *head1 = tempHead;
    *tail1 = tempTail;
    tempHead = tempTail = NULL;
  }

  // Remaining dividend is the remainder → copy to result
  copy_list(*head1, *tail1, headR, tailR);

  return SUCCESS;
}
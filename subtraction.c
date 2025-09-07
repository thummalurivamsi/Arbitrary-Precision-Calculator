/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
  Dlist *t1 = *tail1;
  Dlist *t2 = *tail2;
  int borrow = 0;

  while (t1 || t2)
  {
    int val1 = (t1) ? t1->data : 0;
    int val2 = (t2) ? t2->data : 0;

    int diff = val1 - val2 - borrow;

    if (diff < 0)
    {
      diff += 10;
      borrow = 1;
    }
    else
    {
      borrow = 0;
    }

    insert_at_front(headR, tailR, diff);

    if (t1)
      t1 = t1->prev;
    if (t2)
      t2 = t2->prev;
  }

  // Remove leading zeros (if any)
  while (*headR && (*headR)->data == 0 && (*headR)->next)
  {
    delete_at_front(headR, tailR);
  }

  return SUCCESS;
}

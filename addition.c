/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *t1 = *tail1;
	Dlist *t2 = *tail2;
	int carry = 0;

	while (t1 || t2)
	{
		int sum = carry;

		if (t1)
		{
			sum += t1->data;
			t1 = t1->prev;
		}

		if (t2)
		{
			sum += t2->data;
			t2 = t2->prev;
		}

		carry = sum / 10;
		int digit = sum % 10;

		// Insert at front
		if (insert_at_front(headR, tailR, digit) == FAILURE)
		{
			printf("Memory allocation failed in addition()\n");
			return FAILURE;
		}
	}

	// If carry remains, insert at front
	if (carry)
	{
		if (insert_at_front(headR, tailR, carry) == FAILURE)
		{
			printf("Memory allocation failed in addition()\n");
			return FAILURE;
		}
	}

	// Remove leading zeros (if any)
	while (*headR && (*headR)->data == 0 && (*headR)->next)
	{
		delete_at_front(headR, tailR);
	}

	return SUCCESS;
}
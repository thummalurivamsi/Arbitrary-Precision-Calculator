/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

// Multiply two numbers represented as doubly linked lists
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    if (!head1 || !tail1 || !*head1 || !*tail1 ||
        !head2 || !tail2 || !*head2 || !*tail2)
    {
        printf("Error: one or both numbers are empty\n");
        return FAILURE;
    }

    *headR = *tailR = NULL; // Final result
    Dlist *headR1 = NULL, *tailR1 = NULL; // store accumulated sum
    Dlist *headR2 = NULL, *tailR2 = NULL; // store current partial product

    Dlist *t2 = *tail2; // Least significant digit of 2nd number
    int count = 0;

    while (t2)
    {
        int d2 = t2->data;
        int carry = 0;
        headR2 = tailR2 = NULL; // reset for each partial product

        Dlist *t1 = *tail1;
        while (t1)
        {
            int d1 = t1->data;
            int mul = d1 * d2 + carry;
            carry = mul / 10;
            insert_at_front(&headR2, &tailR2, mul % 10);
            t1 = t1->prev;
        }
        if (carry > 0)
            insert_at_front(&headR2, &tailR2, carry);

        // Append zeros for place value
        for (int i = 0; i < count; i++)
            insert_at_last(&headR2, &tailR2, 0);

        // Add accumulated result (headR1) + current partial product (headR2) -> headR
        addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);

        // Free old accumulated result
        free_list(&headR1, &tailR1);
        // Free used partial product
        free_list(&headR2, &tailR2);

        // Move current final result into headR1 for next iteration
        headR1 = *headR;
        tailR1 = *tailR;
        *headR = *tailR = NULL;

        t2 = t2->prev;
        count++;
    }

    // Final result is in headR1, so move it to headR
    *headR = headR1;
    *tailR = tailR1;

    // Remove leading zeros
    remove_front_zeros(headR, tailR);

    // If multiplication produced nothing, insert 0
    if (!*headR)
        insert_at_front(headR, tailR, 0);

    return SUCCESS;
}



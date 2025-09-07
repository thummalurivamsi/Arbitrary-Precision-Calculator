/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

// For subtraction and division to know which operand is higher
int compare_list(Dlist **head1, Dlist **head2)
{
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;

    int len1 = 0, len2 = 0;

    // Calculate lengths in one pass
    while (temp1)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    // Compare based on length first
    if (len1 > len2)
        return 1;
    else if (len1 < len2)
        return -1;

    // Lengths equal → compare digit by digit from head (most significant digit first)
    temp1 = *head1;
    temp2 = *head2;

    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
            return 1;
        else if (temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0; // Both numbers are equal
}

//  Remove leading zeros from the result list
void remove_front_zeros(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && (*head != *tail))
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        if (*head)
            (*head)->prev = NULL;
        free(temp);
    }
}

// divisible by 0
int is_zero(Dlist *head, Dlist *tail)
{
    // Empty list is considered zero
    if (head == NULL)
        return 1;

    Dlist *temp = head;
    while (temp)
    {
        if (temp->data != 0)
            return 0; // Found a non-zero digit → not zero
        temp = temp->next;
    }

    return 1; // All digits were zero
}

// odd exponent
int is_odd(Dlist *head)
{
    if (head == NULL)
        return 0; // empty list → treat as even (0)

    // Move to tail (last digit)
    Dlist *temp = head;
    while (temp->next)
        temp = temp->next;

    // Check last digit
    return (temp->data % 2 != 0);
}

// Copy a number list (src) into (dest)
void copy_list(Dlist *srcH, Dlist *srcT, Dlist **destH, Dlist **destT)
{
    *destH = *destT = NULL;
    Dlist *temp = srcH;
    while (temp)
    {
        insert_at_last(destH, destT, temp->data);
        temp = temp->next;
    }
}
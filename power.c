/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

// Compute base^exponent using big integer lists
int power(Dlist **headB, Dlist **tailB, Dlist **headE, Dlist **tailE, Dlist **headR, Dlist **tailR)
{
    // Initialize result = 1
    *headR = *tailR = NULL;
    insert_at_last(headR, tailR, 1);

    // Exponent = 0 -> return 1
    if ((*headE)->data == 0 && *headE == *tailE)
        return SUCCESS;

    // Copy base and exponent
    Dlist *baseH = NULL, *baseT = NULL;
    copy_list(*headB, *tailB, &baseH, &baseT);

    Dlist *expH = NULL, *expT = NULL;
    copy_list(*headE, *tailE, &expH, &expT);

    // Exponentiation by squaring
    /*
    For very large exponents, you use Exponentiation by Squaring (fast power method)
    //If exponent is even: ab=(a×a)b/2
    //If exponent is odd: ab=a×(ab−1)
    //Example: 2^10=(2^2)^5=4^5
    //To check even/odd and to halve the exponent, you need division by 2
    */
    while (!(expH->data == 0 && expH == expT)) // while exponent > 0
    {
        // If exponent is odd: result = result * base
        if (expT->data % 2 != 0)
        {
            Dlist *tempH = NULL, *tempT = NULL;
            multiplication(headR, tailR, &baseH, &baseT, &tempH, &tempT);
            free_list(headR, tailR); // free previous result
            *headR = tempH;
            *tailR = tempT;
        }

        // base = base * base
        Dlist *tempBaseH = NULL, *tempBaseT = NULL;
        multiplication(&baseH, &baseT, &baseH, &baseT, &tempBaseH, &tempBaseT);
        free_list(&baseH, &baseT);
        baseH = tempBaseH;
        baseT = tempBaseT;

        // exponent = exponent / 2
        divide_by_two(&expH, &expT);
    }

    free_list(&baseH, &baseT);
    free_list(&expH, &expT);

    remove_front_zeros(headR, tailR); // remove any leading zeros
    return SUCCESS;
}

// Divide a number (list) by 2
void divide_by_two(Dlist **head, Dlist **tail)
{
    if (!*head)
        return;

    Dlist *temp = *head;
    int carry = 0;

    while (temp)
    {
        int cur = carry * 10 + temp->data;
        temp->data = cur / 2;
        carry = cur % 2;
        temp = temp->next;
    }

    // Remove leading zeros
    remove_front_zeros(head, tail);
}

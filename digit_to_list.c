/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

/* Helper function to create a new node */
Dlist *createNode(int digit)
{
    Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(FAILURE);
    }
    newNode->data = digit;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int digit_to_list(Dlist **head1, Dlist **tail1, int *sign1,Dlist **head2, Dlist **tail2, int *sign2, char *argv[])
{
    char *num1 = argv[1];
    char *num2 = argv[3];

    // Handle sign for first number
    *sign1 = 0; // 0 = positive, 1 = negative
    int start1 = 0;
    if (num1[0] == '-')
    {
        *sign1 = 1;
        start1 = 1;
    }
    else if (num1[0] == '+')
    {
        start1 = 1;
    }

    // Convert first number digits
    for (int i = start1; num1[i] != '\0'; i++)
    {
        Dlist *node = createNode(num1[i] - '0');
        if (*head1 == NULL)
        {
            *head1 = *tail1 = node;
        }
        else
        {
            (*tail1)->next = node;
            node->prev = *tail1;
            *tail1 = node;
        }
    }

    // Handle sign for second number
    *sign2 = 0; // 0 = positive, 1 = negative
    int start2 = 0;
    if (num2[0] == '-')
    {
        *sign2 = 1;
        start2 = 1;
    }
    else if (num2[0] == '+')
    {
        start2 = 1;
    }

    // Convert second number digits
    for (int i = start2; num2[i] != '\0'; i++)
    {
        Dlist *node = createNode(num2[i] - '0');
        if (*head2 == NULL)
        {
            *head2 = *tail2 = node;
        }
        else
        {
            (*tail2)->next = node;
            node->prev = *tail2;
            *tail2 = node;
        }
    }

    return SUCCESS;
}

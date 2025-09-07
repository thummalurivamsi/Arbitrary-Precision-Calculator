/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
  // Anything Divided by 1 gives the Number itself as a result
  if ((*head2)->next == NULL && (*head2)->data == 1)
  {
    // Quotient = Dividend
    copy_list(*head1, *tail1, headR, tailR);
    return SUCCESS;
  }
  // Case: dividend < divisor → quotient = 0
  if (compare_list(head1, head2) < 0)
  {
    insert_at_last(headR, tailR, 0);
    return SUCCESS;
  }

  // Initialize quotient as 0 in headR/tailR
  insert_at_last(headR, tailR, 0);

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

    // Increment quotient stored in headR/tailR
    add_one_to_list(headR, tailR);
  }

  return SUCCESS;
}

void add_one_to_list(Dlist **head, Dlist **tail)
{
  Dlist *temp = *tail; // Start from the LSB
  int carry = 1;       // Initialize carry as 1 because we are adding 1

  // Traverse the list backward until carry is 0 or we reach the head
  while (temp && carry)
  {
    int sum = temp->data + carry; // Add carry to current digit 0 + 1
    temp->data = sum % 10;        // Update current digit (keep only units place)
    carry = sum / 10;             // Update carry (1 if sum >= 10, else 0)
    temp = temp->prev;            // Move to previous (more significant) digit
  }

  // If carry is still 1 after reaching the most significant digit
  // it means we need to add a new node at the front
  if (carry)
  {
    Dlist *newNode = createNode(carry); // Create new node with carry (usually 1)
    newNode->next = *head;              // Link new node to current head
    (*head)->prev = newNode;            // Set previous of old head to new node
    *head = newNode;                    // Update head to point to new most significant digit
  }
}

/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

int main(int argc, char *argv[])
{
    // Expecting: ./a.out <number1> <operator> <number2>
    if (read_and_validate(argc, argv) == FAILURE)
        return FAILURE;

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    int sign1 = 0, sign2 = 0, sign_flag = 0;

    // Validate operator & set result sign behavior
    char operator = validate_operands(argv[1], argv[3], argv[2][0], &sign_flag);
    if (operator == 'e')
        return FAILURE;

    // Convert input numbers to linked lists
    if (digit_to_list(&head1, &tail1, &sign1, &head2, &tail2, &sign2, argv) == FAILURE)
        return FAILURE;

    // Make copies for printing original operands
    Dlist *op1_copy_head = NULL, *op1_copy_tail = NULL;
    copy_list(head1, tail1, &op1_copy_head, &op1_copy_tail);

    Dlist *op2_copy_head = NULL, *op2_copy_tail = NULL;
    copy_list(head2, tail2, &op2_copy_head, &op2_copy_tail);

    // Perform operation
    switch (operator)
    {
    case '+':
        if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
            return FAILURE;
        break;

    case '-':
    {
        int cmp = compare_list(&head1, &head2);

        if (cmp == 0)
        {
            insert_at_last(&headR, &tailR, 0); // result = 0
        }
        else if (cmp == 1)
        {
            subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            if (sign1)
                sign_flag = 1;
        }
        else
        {
            subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
            sign_flag = !sign_flag; // flip sign
        }
        break;
    }

    case 'x':
        multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        if (sign1 ^ sign2)
            sign_flag = 1; // XOR for sign
        break;

    case '/':
        if (is_zero(head2, tail2))
        {
            printf("Error: Division by zero\n");
            return FAILURE;
        }
        division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        break;

    case '%':
        if (is_zero(head2, tail2))
        {
            printf("Error: Modulo by zero\n");
            return FAILURE;
        }
        modulo(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        if (sign1)
            sign_flag = 1; // result takes dividend sign
        break;

    case 'p':
        power(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        if (sign1 && is_odd(head2))
            sign_flag = 1; // negative base & odd exponent
        break;

    default:
        printf("Invalid operator: %c. Use +, -, x (*), /, %%, or p (^)\n", operator);
        return FAILURE;
    }

    // Print operand 1
    if (argv[1][0] == '-')
        printf("-");
    print_list(op1_copy_head);

    printf(" %s ", argv[2]); // operator

    // Print operand 2
    if (argv[3][0] == '-')
        printf("-");
    print_list(op2_copy_head);

    printf(" = ");

    // Print result
    if (sign_flag)
        printf("-");
    print_list(headR);

    printf("\n");

    // Free all lists
    free_list(&head1, &tail1);
    free_list(&head2, &tail2);
    free_list(&headR, &tailR);
    free_list(&op1_copy_head, &op1_copy_tail);
    free_list(&op2_copy_head, &op2_copy_tail);

    return SUCCESS;
}

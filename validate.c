/*
  Documentation
  Name         : Vamsi Thummaluri
  Date         : 25/8/25
  Description  : APC project
*/

#include "apc.h"

char validate_operands(const char *num1, const char *num2, char input_operator, int *sign_flag)
{
    int sign1 = (num1[0] == '-') ? 1 : 0;
    int sign2 = (num2[0] == '-') ? 1 : 0;
    const char *abs_num1 = skip_leading_zeros(num1 + sign1);
    const char *abs_num2 = skip_leading_zeros(num2 + sign2);

    int cmp = compare_abs(abs_num1, abs_num2);

    switch (input_operator)
    {
    case '+':
        if (sign1 == sign2)
        {
            *sign_flag = sign1;
            return '+';
        }
        else
        {
            if (cmp)
            {
                *sign_flag = sign1;
                return '-';
            }
            else
            {
                *sign_flag = sign2;
                return '-';
            }
        }

    case '-':
        if (sign1 != sign2)
        {
            *sign_flag = sign1;
            return '+';
        }
        else
        {
            if (cmp)
            {
                *sign_flag = sign1;
                return '-';
            }
            else
            {
                *sign_flag = 1 - sign1;
                return '-';
            }
        }

    case 'x':
        *sign_flag = (sign1 == sign2) ? 0 : 1;
        return 'x';

    case '/':
        if (strcmp(abs_num2, "0") == 0)
        {
            printf("Error: Division by zero\n");
            return 'e'; // error indicator
        }
        *sign_flag = (sign1 == sign2) ? 0 : 1;
        return '/';

    case '%':
        if (strcmp(abs_num2, "0") == 0)
        {
            printf("Error: Modulo by zero\n");
            return 'e'; // error indicator
        }
        *sign_flag = sign1; // result sign follows dividend (num1)
        return '%';

    case 'p':
    {
        // Remove leading zeros from exponent string
        const char *exp_str = skip_leading_zeros(abs_num2);

        // If exponent is zero, result is always 1 (positive)
        if (strcmp(exp_str, "0") == 0)
        {
            *sign_flag = 0; // result is positive
            return 'p';     // power operation
        }

        // Determine if exponent is odd by checking the last digit
        int last_digit = exp_str[strlen(exp_str) - 1] - '0';
        int exp_is_odd = (last_digit % 2);

        // If base is negative and exponent is odd, result is negative; otherwise positive
        if (sign1 == 1 && exp_is_odd)
            *sign_flag = 1; // negative result
        else
            *sign_flag = 0; // positive result

        return 'p';
    }

    default:
        printf("Invalid operator: %c. Use +, -, x (*), /, %%, or p (^)\n", input_operator);
        return 'e'; // error indicator
    }
}

const char *skip_leading_zeros(const char *str)
{
    while (*str == '0' && *(str + 1) != '\0')
        str++;
    return str;
}
// Compares absolute values of two numeric strings (no sign, only digits)
// Returns 1 if abs_num1 >= abs_num2, else 0
int compare_abs(const char *abs_num1, const char *abs_num2)
{
    int len1 = strlen(abs_num1);
    int len2 = strlen(abs_num2);

    // Compare lengths first
    if (len1 > len2)
        return 1; // abs_num1 is greater
    else if (len1 < len2)
        return 0; // abs_num1 is smaller
    else
    {
        // Same length, compare digit by digit
        for (int i = 0; i < len1; i++)
        {
            if (abs_num1[i] > abs_num2[i])
                return 1;
            else if (abs_num1[i] < abs_num2[i])
                return 0;
            // If equal, continue checking next digits
        }
        // All digits equal
        return 1;
    }
}

int is_valid_number(const char *str)
{
    int i = 0;

    // Allow optional leading '+' or '-'
    if (str[0] == '+' || str[0] == '-')
    {
        i = 1;
        if (str[1] == '\0') // string cannot be only '+' or '-'
            return 0;
    }

    // Ensure remaining characters are all digits
    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1; // valid
}

int read_and_validate(int argc, char *argv[])
{

    // Validate operator (must be a single character and in allowed set)
    if (strlen(argv[2]) != 1 ||
        !(argv[2][0] == '+' || // Addition
          argv[2][0] == '-' || // Subtraction
          argv[2][0] == 'x' || // Multiplication
          argv[2][0] == '/' || // Division
          argv[2][0] == '%' || // modulo
          argv[2][0] == 'p'))  // power
    {
        printf("Error: Invalid operator '%s'. Use only +, -, x (*), /, %%, p (^)\n", argv[2]);
        return FAILURE;
    }

    // Minimum argument check
    if (argc != 4)
    {
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        return FAILURE;
    }

    // Validate number1 (argv[1])
    if (!is_valid_number(argv[1]))
    {
        printf("Error: Invalid number '%s'. Must contain only digits, optionally starting with + or -\n", argv[1]);
        return FAILURE;
    }

    // Validate number2 (argv[3])
    if (!is_valid_number(argv[3]))
    {
        printf("Error: Invalid number '%s'. Must contain only digits, optionally starting with + or -\n", argv[3]);
        return FAILURE;
    }

    return SUCCESS;
}

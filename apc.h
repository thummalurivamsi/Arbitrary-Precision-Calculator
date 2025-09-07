#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
} Dlist;

int read_and_validate(int argc, char *argv[]);
int is_valid_number(const char *str);
Dlist *createNode(int digit);
int compare_list(Dlist **head1, Dlist **head2);
/* Convert input numbers (from argv) into two doubly linked lists */
int digit_to_list(Dlist **head1, Dlist **tail1, int *sign1, Dlist **head2, Dlist **tail2, int *sign2, char *argv[]);

/* Arithmetic Operations */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int modulo(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int power(Dlist **headB, Dlist **tailB, Dlist **headE, Dlist **tailE,
		  Dlist **headR, Dlist **tailR);

/* Utility Functions */
int insert_at_front(Dlist **head, Dlist **tail, int digit);
int insert_at_last(Dlist **head, Dlist **tail, int data);
int insert_at_rear(Dlist **head, Dlist **tail, int digit);
void delete_at_front(Dlist **head, Dlist **tail);
void print_list(Dlist *head);
void free_list(Dlist **head, Dlist **tail);
void remove_front_zeros(Dlist **head, Dlist **tail);
void copy_list(Dlist *srcH, Dlist *srcT, Dlist **destH, Dlist **destT);
void divide_by_two(Dlist **head, Dlist **tail);
void add_one_to_list(Dlist **head, Dlist **tail);
char validate_operands(const char *num1, const char *num2, char input_operator, int *sign_flag);
const char *skip_leading_zeros(const char *str);
int is_zero(Dlist *head, Dlist *tail);
int is_odd(Dlist *head);
int compare_abs(const char *abs_num1, const char *abs_num2);

#endif

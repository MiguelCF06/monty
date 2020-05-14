#include "monty.h"
/**
 *_div - Divides the top two elements of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			freeAll(stack);
			exit(EXIT_FAILURE);
		}
		(*stack)->next->n /= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 *mul - Multiplies the top two elements of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 *mod - Divides the top two elements of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			freeAll(stack);
			exit(EXIT_FAILURE);
		}
		(*stack)->next->n %= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 *pchar - Prints the char at the top of the stack
 *@stack: The doubly linked list
 *@line_number: The line of the text
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack && stack)
	{
		if ((*stack)->n >= 32 && (*stack)->n < 127)
			printf("%c\n", (*stack)->n);
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			freeAll(stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 *pstr - Prints a string starting at the top of the stack
 *@stack: The doubly linked list
 *@line_number: The line of the text
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (*stack)
	{
		while (temp && temp->n != 0)
		{
			if (temp->n >= 32 && temp->n < 127)
				printf("%c", temp->n);
			else
				break;
			temp = temp->next;
		}
		printf("\n");
	}
	else
		printf("\n");
}

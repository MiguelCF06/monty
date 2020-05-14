#include "monty.h"
/**
 *pint - Prints the value at the top of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 *pop - Removes the top element of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stack && *stack)
	{
		*stack = temp->next;
		if (temp->next != NULL)
			temp->next->prev = temp->prev;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 *swap - Swaps the two elements of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 *add - Adds the top two elements of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
}

#include "monty.h"
/**
 *pint - Prints the value at the top of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 *pop - Removes the top element of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
void pop(stack_t **stack, unsigned int line_number)
 */

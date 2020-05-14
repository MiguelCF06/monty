#include "monty.h"
/**
 *pint - Prints the value at the top of the stack
 *@stack: The doubly linked list
 *@line_number: Line of the text
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack && stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}
	
}

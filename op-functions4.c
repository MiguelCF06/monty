#include "monty.h"
/**
 *rotl - Rotates the stack to the top
 *@stack: The doubly linked list
 *@line_number: The line of the text
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp && temp->next)
		temp = temp->next;

	temp->next = *stack;
	*stack = (*stack)->next;
	temp->next->next = NULL;
	temp->next->prev = temp;
}

/**
 *rotr - Rotates the stack to the bottom
 *@stack: The doubly linked list
 *@line_number: The line of the text
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp && temp->next)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}

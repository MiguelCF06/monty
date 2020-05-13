#include "monty.h"
/**
 * push - pushes an element to beginning of stack.
 * @stack: doubly linked list.
 * @line_number: number of lines.
 *Return: nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!globalVariable.arguments)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*globalVariable.arguments != '0' && !atoi(globalVariable.arguments))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}

	if (new_node)
	{
		new_node->n = atoi(globalVariable.arguments);
		new_node->next = *stack;
		new_node->prev = NULL;

		if (*stack)
			(*stack)->prev = new_node;
		(*stack) = new_node;
	}
}
/**
 * pall - prints stack elements.
 * @line_number: line number.
 * @stack: doubly linked list.
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * nop - does nothing.
 * @stack: doubly linked list.
 * @line_number: line number.
 * Return: nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}

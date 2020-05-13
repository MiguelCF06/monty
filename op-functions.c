#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!globalVariable.arguments || !atoi(globalVariable.arguments))
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(new_node);
		freeAll(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(globalVariable.arguments);
	new_node->next = NULL;
	new_node->prev = *stack;

	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
}


void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}

#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!globalVariable.arguments)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
                exit(EXIT_FAILURE);
	}

	if (*globalVariable.arguments != '0' && !atoi(globalVariable.arguments))
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
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

void nop(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}

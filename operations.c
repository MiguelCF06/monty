#include "monty.h"
/**
 * findOption - Sends operation to its respective function for execution
 * @stack: doubly linked list of stack.
 * @line_number: line number.
 * Return: 1 if it was successful or 0 if there was an error.
 */
int findOption(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, globalVariable.operation) == 0)
		{
			ops[i].f(stack, line_number);
			return (0);
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
		globalVariable.operation);
	freeAll(stack);
	exit(EXIT_FAILURE);
	return (1);
}

/**
 * freeAll - frees all pointers, closes file pointer.
 * @stack: doubly linked list to be freed.
 * Return: None.
 */
void freeAll(stack_t **stack)
{
	stack_t *temp = *stack;

	if (*stack)
	{
		while (*stack)
		{
			*stack = (*stack)->next;
			free(temp);
			temp = *stack;
		}
	}
	free(globalVariable.buffer);
	fclose(globalVariable.montyfile);
}

#include "monty.h"

int findOption(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode,globalVariable.operation) == 0)
		{
			ops[i].f(stack, line_number);
			return 0;
		}
	}
	
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, globalVariable.operation);
	freeAll(stack);
	exit(EXIT_FAILURE);
	return (1);
}

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

#include "monty.h"

global_t globalVariable = {NULL, NULL, NULL, NULL, NULL, 0};

/**
 *main - Open the monty file that is passed.
 *@argc:The count of arguments
 *@argv: The arguments vector (in this case will be the file to open)
 *Return: Exit with success or Exit with failure
 */
int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globalVariable.namefile = argv[1];
	readFile(argv[1]);
	parsingFile();
	return (EXIT_SUCCESS);
}

/**
 *readFile - Open and read the monty file
 *@namefile: The name of the monty bytecode file
 */
void readFile(char *namefile)
{
	globalVariable.montyfile = fopen(namefile, "r");

	if (!globalVariable.montyfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", globalVariable.namefile);
		exit(EXIT_FAILURE);
	}
}
/**
 *parsingFile - Parse the text in the file
 *It doesn't need arguments
 */

void parsingFile(void)
{
	size_t size = 0;
	ssize_t reading = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	while (1)
	{
		reading = getline(&globalVariable.buffer, &size,
			       globalVariable.montyfile);
		if (reading == -1)
			break;

		globalVariable.operation = strtok(globalVariable.buffer, " \t\n");

		if (!globalVariable.operation || globalVariable.operation[0] == '#')
			globalVariable.operation = "nop";
		globalVariable.arguments = strtok(NULL, " \t\n");

		findOption(&stack, line_number);
		line_number++;
	}

	freeAll(&stack);
}

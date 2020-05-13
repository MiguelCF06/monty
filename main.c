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

void readFile(char *namefile)
{
	globalVariable.montyfile = fopen(namefile, "r");
	if (!globalVariable.montyfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", globalVariable.namefile);
		fclose(globalVariable.montyfile);
		exit(EXIT_FAILURE);
	}
	
}

void parsingFile(void)
{
	size_t size;
	
	while (getline(&globalVariable.buffer, &size, globalVariable.montyfile))
	{
	        globalVariable.operation = strtok(globalVariable.buffer, " \n");
		if (globalVariable.operation[0] == '#')
			globalVariable.operation = "nop";
	}
	globalVariable.arguments = strtok(NULL, " \n");
}

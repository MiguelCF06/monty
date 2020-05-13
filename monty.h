#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *struct global_s - Global structure
 *@operation: The operation that the montyfile wants to do
 *@arguments: The arguments of the operation(what thing you want to put)
 *@buffer: The buffer where is every string of the file
 *@montyfile: The monty bytecode file
 *@namefile: The name of the bytecode file
 *@stack: The reference to the stack
 */

typedef struct global_s
{
	char *operation;
	char *arguments;
	char *buffer;
	FILE *montyfile;
	char *namefile;
	int *stack;
} global_t;
extern global_t globalVariable;


/*operations*/
int findOption(stack_t **stack, unsigned int line_number);
void freeAll(stack_t **stack);


/*op-functions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
int _isdigit(char *li);


/*main*/
void readFile(char *namefile);
void parsingFile(void);

#endif

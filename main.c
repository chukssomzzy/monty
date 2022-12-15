# include "monty.h"
#include <stdlib.h>
# define MAX 100

/**
 * main - control the flow of monty interpreter
 *
 * @argc: contains number of arguments giving
 * @argv: holds command line arguments
 *
 * Return: 1 or 0
 */

int main(int argc, char **argv)
{
	size_t line_num = 0, line_size = 0;
	FILE *monty_f;
	char *lineptr = NULL, opcode[MAX];
	long int n;
	stack_t *stack = NULL;
	void (*f)(stack_t **, unsigned int);

	if (argc != 2)
		error_handler(NULL, NULL, "USAGE: monty file", NULL);
	monty_f = fopen(argv[1], "rb");
	if (!monty_f)
		error_handler(NULL, NULL, NULL, argv[1]);
	while (getline(&lineptr, &line_size, monty_f) != -1)
	{
		line_num++;
		n = 0;
		if (get_opcodes(opcode, &n, lineptr, line_size))
			f = get_stackop(opcode, line_num);
		else
			continue;
		if (f && !n && check_op_ex(opcode))
			error_handler(&line_num, opcode, NULL, NULL);
		if (f)
			f(&stack, n);
		else
			error_handler(&line_num, opcode, "instruct", NULL);
	}
	fclose(monty_f);
	free_stack(stack);
	exit(EXIT_SUCCESS);
}

/**
 * error_handler - print error and exit
 * @line_num: pointer to line_number
 * @error: text to print to stderr
 * @opcode: pointer to invalid opcode
 * @file: pointer to file name
 */

void error_handler(size_t *line_num, char *opcode, char *error, char *file)
{
	if (line_num && error && opcode)
		dprintf(2, "L%lu: unknown instruction %s\n", *line_num, opcode);
	else if (line_num && opcode)
		dprintf(2, "L%lu: usage: %s integer\n", *line_num, opcode);
	else if (error)
		perror(error);
	else if (file)
		dprintf(2, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

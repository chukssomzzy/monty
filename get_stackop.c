#include "monty.h"

/**
 * get_stackop - return a function pointer all exit on invalid opcode
 * @opcode: character string to match in other to fetch the required function
 * @line_num: line number where opcode was found
 *
 * Return: function pointer
 */

void (*get_stackop(char *opcode, int line_num))(stack_t **, unsigned int)
{
	instruction_t instruct_sta[] = {{"push", push_op}, {"pall", pall_op},
									{NULL, NULL}};

	int i = 0;

	while (instruct_sta[i++].opcode)
		if (!strcmp(instruct_sta[i - 1].opcode, opcode))
			return (instruct_sta[i - 1].f);
	if (line_num)
		;
	return (NULL);
}

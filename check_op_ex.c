# include "monty.h"

/**
 * check_op_ex - check if opcode requires argument
 * @opcode: pointer to opcode
 * Return: 0 if it doesn't and 1 if it doesn
 */

int check_op_ex(char *opcode)
{
	char *op_req[] = {"pall", NULL};
	int i = 0;

	while (op_req[i])
		if (!strcmp(opcode, op_req[i++]))
		{
			return (0);
		}
	return (1);
}

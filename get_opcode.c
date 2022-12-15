# include "monty.h"
#include <string.h>
# define BASE10 10
#include <ctype.h>

/**
 * get_opcodes - get opcodes and opcodes arguments
 * @opcode: buffer to store found opcodes
 * @arg: buffer to store opcode arguments
 * @line: pointer to line to search for opcodes
 * @n: size of line
 * Return: 1 if successfull and 0 on failure
 */

int get_opcodes(char *opcode, long int *arg, char *line, size_t n)
{
	size_t i = 0, j = 0;

	while (*(line + i) && i < n)
	{
		if (!(isspace(*(line + i))))
		{
			opcode[j++] = *(line + i);
			if (isspace(*(line + i + 1)))
				break;
		}
		i++;

	}
	if (!(*(line + i)) && !j)
		return (0);
	opcode[j] = '\0';
	*arg = atoi(line + i + 1);
	return (1);
}

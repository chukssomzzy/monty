#include "monty.h"

/**
 * get_stackop - return a function pointer all exit on invalid opcode
 * @sta: character string to match in other to fetch the required function
 * @lin: line number where opcode was found
 *
 * Return: function pointer
 */

void (*get_stackop(stack_t **sta, unsigned int lin))(stack_t **, unsigned int)
{
	instruction_t instruct_sta[] = {{"push", push_op}, {"pall", pall_op}, {"pint",
		pint_op}, {"pop", pop_op}, {"swap", swap_op}, {"add", add_op},
				  {NULL, NULL}};
	unsigned int i = 0;
	char *op;

	op = strtok(state.content, " \n\t");
	if (op && op[0] == '#')
		return (NULL);
	state.arg = strtok(NULL, " \n\t");
	while (instruct_sta[i].opcode && op)
	{
		if (!strcmp(op, instruct_sta[i].opcode))
		{
			return (instruct_sta[i].f);
		}
		i++;
	}
	if (op && instruct_sta[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", lin, op);
		fclose(state.file);
		free(state.content);
		free_stack(*sta);
		exit(EXIT_FAILURE); }
	return (NULL);
}

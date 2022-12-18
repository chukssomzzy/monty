# include "monty.h"

/**
 * pstr_op - print ascii on a stack
 * @t: double pointer to stack
 * @line_num: line number
 */

void pstr_op(stack_t **t, op_size __attribute__((unused)) line_num)
{
	stack_t *tmp;

	if ((t && !(*t)) || !t)
	{
		putchar('\n');
		return;
	}
	tmp = *t;
	while (tmp)
	{
		if (!tmp->n || !_isascii(tmp->n))
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}

# include "monty.h"

/**
 * sub_op - subtract two top level element
 * @t: double pointer to a stack
 * @line_num: line number
 */

void sub_op(stack_t **t, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *t;
	if ((t && !(*t)) || !t)
		cleanup(*t, line_num, "can't sub, stack too short");
	if ((tmp && !tmp->next) || !tmp)
		cleanup(*t, line_num, "can't sub, stack too short");
	(*t)->next->n -= (tmp->n);
	*t = (*t)->next;
	free(tmp);
}

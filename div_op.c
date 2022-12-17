# include "monty.h"

/**
 * div_op - subtract two top level element
 * @t: double pointer to a stack
 * @line_num: line number
 */

void div_op(stack_t **t, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *t;
	if ((t && !(*t)) || !t)
		cleanup(*t, line_num, "can't div, stack too short");
	if ((tmp && !tmp->next) || !tmp)
		cleanup(*t, line_num, "can't div, stack too short");
	if (!tmp->n)
		cleanup(*t, line_num, "division by zero");
	(*t)->next->n /= tmp->n;
	(*t)->next->prev = NULL;
	*t = (*t)->next;
	free(tmp);
}

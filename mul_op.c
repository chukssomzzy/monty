# include "monty.h"

/**
 * mul_op - subtract two top level element
 * @t: double pointer to a stack
 * @line_num: line number
 */

void mul_op(stack_t **t, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *t;
	if ((t && !(*t)) || !t)
		cleanup(*t, line_num, "can't mul, stack too short");
	if ((tmp && !tmp->next) || !tmp)
		cleanup(*t, line_num, "can't mul, stack too short");
	(*t)->next->n *= tmp->n;
	(*t)->next->prev = NULL;
	*t = (*t)->next;
	free(tmp);
}

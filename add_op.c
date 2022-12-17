# include "monty.h"

/**
 * add_op - adds two top element and saves in second element
 * @t: double pointer to stack
 * @line_num: line_number
 */

void add_op(stack_t **t, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *t;
	if ((t && !(*t)) || !t)
		cleanup(*t, line_num, "can't add, stack too short");
	if ((tmp && !tmp->next) || !tmp)
		cleanup(*t, line_num, "can't add, stack too short");
	(*t)->next->n += (tmp->n);
	(*t)->next->prev = NULL;
	*t = (*t)->next;
	free(tmp);
}

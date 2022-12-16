# include "monty.h"

/**
 * swap_op - swap the top 2 elements of a stack
 * @t: pointer to stack;
 * @line_num: line_num of code
 */

void swap_op(stack_t **t, unsigned int line_num)
{
	stack_t *tmp, *cur, *next;

	if ((t && !(*t)) || !t)
		cleanup(*t, line_num, "can't swap, stack too short");
	tmp = *t;
	if ((tmp && !tmp->next) || !tmp)
		cleanup(*t, line_num, "can't swap, stack too short");
	while (tmp->prev)
		tmp = tmp->prev;
	cur = tmp;
	tmp = tmp->next;
	next = tmp->next;
	tmp->next = cur;
	cur->next = next;
	cur->prev = tmp;
	tmp->prev = NULL;
	*t = tmp;
}

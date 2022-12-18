# include "monty.h"

/**
 * rotl_op - moves first element to the buttom of stack
 * @t: double pointer to stack
 * @line_num: line number
 */

void rotl_op(stack_t **t, __attribute__((unused)) op_size line_num)
{
	stack_t *tmp, *nxt;

	if ((t && !(*t)) || !t)
		return;
	tmp = *t;
	if ((tmp && !tmp->next) || !tmp)
		return;
	nxt = (*t)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *t;
	(*t)->next = NULL;
	*t = nxt;
	(*t)->prev = NULL;
}

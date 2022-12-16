# include "monty.h"

/**
 * pop_op - pop an element from the stack
 * @stack: double pointer to stack
 * @line_num: line number where code was found
 */

void pop_op(stack_t **stack, unsigned int line_num)
{
	stack_t *next, *tmp;

	if ((stack && !(*stack)))
		cleanup(*stack, line_num, "can't pop an empty stack");
	tmp = *stack;
	while (tmp->prev)
		tmp = tmp->prev;
	next = tmp->next;
	free(tmp);
	if (next)
		next->prev = NULL;
	*stack = next;
}

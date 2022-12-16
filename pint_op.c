# include "monty.h"

/**
 * pint_op - print value at the top of the stack
 * @stack: pointer to stack
 * @line_num: line number of code
 */

void pint_op(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if ((stack && !(*stack)) || !stack)
		cleanup(*stack, line_num, "can't pint, stack empty");
	tmp = *stack;
	if (tmp->prev)
		tmp = tmp->prev;
	printf("%i\n", tmp->n);
}



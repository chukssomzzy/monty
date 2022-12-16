# include "monty.h"

/**
 * pall_op - print all element on stack
 * @t: double pointer to stackto print
 * @n: line number of code
 */

void pall_op(stack_t **t, __attribute__ ((unused)) unsigned int n)
{
	stack_t *tmp;

	if (!t)
		return;
	tmp = *t;

	while (tmp)
	{
		printf("%u\n", tmp->n);
		tmp = tmp->next;
	}
}

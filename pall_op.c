# include "monty.h"

/**
 * pall_op - print all element on stack
 * @t: double pointer to stackto print
 * @n: line number of code
 */

void pall_op(stack_t **t, __attribute__ ((unused)) unsigned int n)
{
	stack_t *tmp;

	if ((t && !(*t)) || !t)
		return;
	tmp = *t;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

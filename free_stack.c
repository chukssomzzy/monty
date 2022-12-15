# include "monty.h"

/**
 * free_stack - free a free_stack
 * @t: pointer to free_stack
 */

void free_stack(stack_t *t)
{
	stack_t *next;

	if (!t)
		return;
	next = t->next;
	free(t);
	free_stack(next);
}

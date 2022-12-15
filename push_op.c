# include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push_op - push an integer to the stack
 * @t: stack to push integer
 * @n: unsigned int to push to stack
 */

void push_op(stack_t **t, unsigned int n)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	tmp = *t;
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (t && !(*t))
	{
		*t = new;
		return;
	}
	new->next = tmp;
	tmp->prev = new;
	*t = new;
}

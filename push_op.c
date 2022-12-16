#include "monty.h"
static void cleanup(stack_t *head, unsigned int counter);

/**
 * push_op - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void push_op(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (state.arg)
	{
		if (state.arg[0] == '-')
			j++;
		for (; state.arg[j] != '\0'; j++)
		{
			if (state.arg[j] > 57 || state.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
			cleanup(*head, counter);
	}
	else
		cleanup(*head, counter);
	n = atoi(state.arg);
	if (state.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * cleanup - close all buffers and exit
 * @head: head of stack
 * @counter: line_number
 */

void cleanup(stack_t *head, unsigned int counter)
{
	fprintf(stderr, "L%d: usage: push integer\n", counter);
	fclose(state.file);
	free(state.content);
	free_stack(head);
	exit(EXIT_FAILURE);
}

#include "monty.h"


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
			cleanup(*head, counter, "usage: push integer");
	}
	else
		cleanup(*head, counter, "usage: push integer");
	n = atoi(state.arg);
	if (state.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * cleanup - close all buffers and exit
 * @head: head of stack
 * @line_num: line_number
 * @err: error message
 */

void cleanup(stack_t *head, unsigned int line_num, char *err)
{
	fprintf(stderr, "L%d: %s\n", line_num, err);
	fclose(state.file);
	free(state.content);
	free_stack(head);
	exit(EXIT_FAILURE);
}

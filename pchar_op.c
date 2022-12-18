# include "monty.h"

/**
 * pchar_op - print ascii at top
 * @t: double pointer to stack
 * @line_num: line_number
 */
void pchar_op(stack_t **t, unsigned int line_num)
{

	if ((t && !(*t)) || !t)
		cleanup(*t, line_num, "can't pchar, stack empty");
	if (!_isascii((*t)->n))
		cleanup(*t, line_num, "can't pchar, value out of range");
	putchar((*t)->n);
	putchar('\n');
}

/**
 * _isascii - test if a int is an ascii
 * @t_char: int to test
 * Return: 1 or 0
 */

int _isascii(int t_char)
{
	return (t_char >= 0 && t_char <= 127);
}

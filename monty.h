# ifndef MONTY_H
# define MONTY_H
# define _POSIX_C_SOURCE 200809L
#include <stdint.h>
# include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct state_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: queue or stack
 * Description: carries values through the program
 */
typedef struct state_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  state_t;
extern state_t state;
void(*get_stackop(stack_t **stack, unsigned int counter)) (stack_t **, unsigned int);
void free_stack(stack_t *);
void push_op(stack_t **, unsigned int);
void pall_op(stack_t **t, unsigned int n);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);

# endif

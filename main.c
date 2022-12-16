# include "monty.h"
state_t state = {NULL, NULL, NULL, 0};
/**
 * main - control the flow of monty interpreter
 *
 * @argc: contains number of arguments giving
 * @argv: holds command line arguments
 *
 * Return: 1 or 0
 */

int main(int argc, char **argv)
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_num = 0;
	void (*f)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	state.file = file;
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		state.content = content;
		line_num++;
		if (read_line > 0)
		{
			f = get_stackop(&stack, line_num);
			if (f)
				f(&stack, line_num);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}


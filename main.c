#include "monty.h"
int gnumber = 0;
/**
 * main - Entry point
 * @argc: number of arguments passed
 * @argv: array of arguments passed
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	ssize_t line_chars = 0;
	size_t line_len = 0;
	unsigned int line_number = 1;
	char *line_buf = NULL;
	char *tok_op = NULL, *tok_num;
	stack_t *stack = NULL;

	check_args(argc);

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line_chars = getline(&line_buf, &line_len, file)) != -1)
	{
		tok_op = strtok(line_buf, " \t\n\r");
		tok_num = strtok(NULL, " \t\n\r");
		if (tok_op == NULL)
		{
			line_number++;
			continue;
		}

		if (strcmp(tok_op, "push") == 0)
			tok_valid(tok_num, line_number);
		find_op(&stack, tok_op, line_number);
		line_number++;
	}
	free(line_buf);
	free_list(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

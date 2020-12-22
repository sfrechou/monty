#include "monty.h"
/**
 * find_op - function to find corresponding opcode if any
 * @stack: list where values will be stored
 * @tok_op: token with the argument
 * @line_number: number of line being read. In case of error
 * Return: 0 on success, 1 on error
 */
int find_op(stack_t **stack, char *tok_op, unsigned int line_number)
{
	instruction_t options[] = {
		{"pall", fpall},
		{"push", fpush},
		{NULL, NULL}
	};
	int i = 0;

	while (options[i].opcode != NULL)
	{
		if (strcmp(options[i].opcode, tok_op) == 0)
		{
			options[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * fpush - point of entry.
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fpush(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	(void)line_number;

	newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	newnode->n = gnumber;
	newnode->next = (*stack);
	newnode->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = newnode;

	*stack = newnode;
}

/**
 * fpall - point of entry.
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fpall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	free_list(*stack);
}

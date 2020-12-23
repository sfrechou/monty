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
		{"pint", fpint},
		{"pop", fpop},
		{"swap", fswap},
		{"add", fadd},
		{"nop", fnop},
		{"sub", fsub},
		{"div", fdiv},
		{"mul", fmul},
		{"mod", fmodu},
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
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, tok_op);
	free_list(*stack);
	exit(EXIT_FAILURE);
}

/**
 * fpush - pushes an element to the stack
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fpush(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	(void)line_number;
	if (stack == NULL)
	{
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
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
 * fpall - prints stack LIFO
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fpall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (stack == NULL)
	{
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * fpint - prints value at top of stack.
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fpint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * fpop - prints value at top of stack.
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fpop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop, stack empty stack\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	free(temp);
}

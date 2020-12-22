#include "monty.h"

void find_op(stack_t **stack, char *tok_op, unsigned int line_number)
{
    instruction_t options[] = {
		{"pall", fpall},
		{"push", fpush},
		{NULL, NULL}
	};
	int i = 0;
    (void)line_number;
	while (options[i].opcode != NULL)
	{
		if (strcmp(options[i].opcode, tok_op) == 0)
		{
			options[i].f(stack, line_number);
		}
		i++;
	}
}

void fpush(stack_t **stack, unsigned int line_number)
{
    stack_t *newnode = NULL;
    (void)line_number;

    newnode = malloc(sizeof(stack_t));

    if (newnode == NULL)
    {
        exit(EXIT_FAILURE);
    }
    newnode->n = gnumber;
    newnode->next = (*stack);
    newnode->prev = NULL;
    if ((*stack) != NULL)
		(*stack)->prev = newnode;

    *stack = newnode;
}

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
}
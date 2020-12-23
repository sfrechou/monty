#include "monty.h"
/**
 * stack_tlen - function that prints number of elements in list
 * @h: pointer to list to print
 *
 * Return: elements in list
 */
size_t stack_tlen(stack_t **h)
{
	size_t elements = 0;
	stack_t *temp;

	if (*h == NULL)
	{
		return (elements);
	}
	temp = *h;
	while (temp != NULL)
	{
		temp = temp->next;
		elements++;
	}
	return (elements);
}
/**
 * fmul - multiplies first two elements of stack.
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fmul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int mul = 0;
	size_t len = 0;

	len = stack_tlen(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->next->n * (*stack)->n;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n = mul;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * fmodu - multiplies first two elements of stack
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fmodu(stack_t **stack, unsigned int line_number)
{
	stack_t *len = *stack, *temp = *stack;
	int count = 1, add = 0;

	while (len->next != NULL)
	{
		count++;
		len = len->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	add = temp->next->n % temp->n;
	(*stack) = temp->next;
	(*stack)->n = add;
	(*stack)->prev = NULL;
}

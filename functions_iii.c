#include "monty.h"
/**
 * dlistint_len - function that prints number of elements in list
 * @h: pointer to list to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
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
 * fmul - multiplies first two elements of stack. Stores result in elm2, deletes elm1
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fmul(stack_t **stack, unsigned int line_number)
{
	stack_t *len = *stack, *temp = *stack, *aux;
	int count = 1, add = 0;

	while (len->next != NULL)
	{
		count++;
		len = len->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	
	add = temp->next->n * temp->n;
	aux = temp;
	(*stack) = temp->next;
	(*stack)->n = add;
	(*stack)->prev = NULL;
	free(aux);
}

/**
 * fmodu - multiplies first two elements of stack. Stores result in elm2, deletes elm1
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
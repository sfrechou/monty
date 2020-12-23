#include "monty.h"
/**
 * fmul - multiplies first two elements of stack. Stores result in elm2, deletes elm1
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fmul(stack_t **stack, unsigned int line_number)
{
	stack_t *len = *stack, *temp = *stack, *aux;
	int count = 0, add = 0;

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
	stack_t *len = *stack, *temp = *stack, *aux;
	int count = 0, add = 0;

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
	add = temp->next->n % temp->n;
	aux = temp;
	(*stack) = temp->next;
	(*stack)->n = add;
	(*stack)->prev = NULL;
	free(aux);
}
#include "monty.h"
/**
 * fswap - swaps first two elements of stack
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fswap(stack_t **stack, unsigned int line_number)
{
	stack_t *len = *stack, *temp = *stack;
	int count = 0, swap = 0;

	while (len->next != NULL)
	{
		len = len->next;
		count++;
	}
	count++;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(len);
		free(temp);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	swap = temp->n;
	temp->n = temp->next->n;
	temp->next->n = swap;
}
/**
 * fadd - adds first two elements of stack. Stores result in elm2, deletes elm1
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fadd(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	add = temp->n + temp->next->n;
	aux = temp;
	(*stack) = temp->next;
	(*stack)->n = add;
	(*stack)->prev = NULL;
	free(aux);
}

/**
 * fnop - does not do anything
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fnop(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}

/**
 * fsub - subtracts first two elements of stack. Stores result in elm2, deletes elm1
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fsub(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	add = temp->next->n - temp->n;
	aux = temp;
	(*stack) = temp->next;
	(*stack)->n = add;
	(*stack)->prev = NULL;
	free(aux);
}

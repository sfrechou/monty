#include "monty.h"
/**
 * free_list - function to free the stack
 * @stack: linked list to be freed
 *
 * Return: void.
 */
void free_list(stack_t *stack)
{
	stack_t *aux;

	while (stack)
	{
		aux = stack;
		stack = stack->next;
		free(aux);
	}
	free(stack);
}

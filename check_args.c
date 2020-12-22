#include "monty.h"
/**
 * check_args - check if argc has correct amount
 * @argc: amount of arguments passed
 * Return: void
 */
void check_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

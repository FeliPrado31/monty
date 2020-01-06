#include "monty.h"
/**
 * _pint - prints of the stack
 * @stack: double pointer  head of the stack.
 * @line: counter for line number of the file.
 *
 * Return: void.
 */
void _pint(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", tmp->n);
}

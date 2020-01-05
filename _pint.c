#include "monty.h"
/**
 * _pint - Print the value at the top of the stack
 * @stack: pointer to stack
 * @line: line number
 */
void _pint(stack_t **stack, unsigned int line)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (node->next)
			node = node->next;
		dprintf(STDOUT_FILENO, "%d\n", node->n);
	}
}

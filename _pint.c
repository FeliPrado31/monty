#include "monty.h"
/**
 * exe_pint - Print the value at the top of the stack
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just print the top value
 */
void exe_pint(stack_t **stack, unsigned int ln)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty", ln);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (node->next)
			node = node->next;
		dprintf(STDOUT_FILENO, "%d\n", node->n);
	}
}
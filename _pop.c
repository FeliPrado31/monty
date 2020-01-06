#include "monty.h"

/**
 * execute_pop - remove the first elemnt of the stack
 * @stack: The stack
 * @line: The current file line number
 */
void _pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp = tmp->next;
	free(*stack);
	*stack = tmp;
}

#include "monty.h"
/**
 * _pop -  The opcode pop removes the top element of the stack.
 * @stack: stack of the list
 * @line: the list
 *
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		free_all(*(stack));
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (*stack != NULL)
		tmp->prev = NULL;
}

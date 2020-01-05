#include "monty.h"
/**
 * _add - Add the top two elements
 * @stack: pointer to stack
 * @line: line number
 * Return: Nothing, just add
 */
void _add(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;

	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line);
		free_all((*stack));
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->n += tmp->next->n;
		_pop(stack, line);
	}

}

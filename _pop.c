#include "monty.h"

/**
 * execute_pop - remove the first elemnt of the stack
 * @stack: The stack
 * @n: The current file line number
 * Return: Nothing or EXIT_FAILURE
 */
void _pop(stack_t **stack, unsigned int line)
{
	stack_t *aux;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	aux = aux->next;
	free(*stack);
	*stack = aux;
}

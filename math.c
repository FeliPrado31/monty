#include "monty.h"

void _add(stack_t **stack, unsigned int line)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line);
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}

	sum = ((*stack)->next)->n + (*stack)->n;

	_pop(stack, line);
	(*stack)->n = sum;
}

/**
 * _sub - subtracts the top element in the stack from the next top element
 * and replaces the top two nodes with the result
 * @stack: stack
 * @line: line number
 */

void _sub(stack_t **stack, unsigned int line)
{
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line);
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}

	sub = ((*stack)->next)->n - (*stack)->n;

	_pop(stack, line);
	(*stack)->n = sub;
}
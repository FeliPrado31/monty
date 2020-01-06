#include "monty.h"

/**
 * _swap -The opcode swap swaps the top two elements of the stack.
 * @stack: this is the head.
 * @line: constant int value
 * Return: is a void
 **/
void _swap(stack_t **stack, unsigned int line)
{
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}

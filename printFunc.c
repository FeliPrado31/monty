#include "monty.h"

/**
 * _rotl - The opcode rotl rotates the stack to the top.
 * @stack: Stack.
 * @line: line of the line where the opcode is taken.
 */
void _rotl(stack_t **stack, unsigned int line)
{
	stack_t *node = *stack;

	(void)line;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (node->next)
		node = node->next;

	node->next = *stack;
	(*stack)->prev = node;
	*stack = (*stack)->next;
	node->next->next = NULL;
	(*stack)->prev = NULL;
}

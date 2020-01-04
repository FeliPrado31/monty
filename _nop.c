#include "monty.h"

/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: stack
 * @line_number: The current file line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack == NULL)
		return;
}

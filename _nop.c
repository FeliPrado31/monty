#include "monty.h"

/**
 * _nop - Funtionces of the opcode nop.
 * @stack: Stack.
 * @line: line of the line where the opcode is taken.
 */
void _nop(stack_t **stack, unsigned int line)
{
	(void) line;
	if (*stack == NULL)
		return;
}

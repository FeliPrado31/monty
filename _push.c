#include "monty.h"
/**
 * _push - Funtionces of the opcode push.
 * @stack: Stack.
 * @line: line of the line where the opcode is taken.
 */
void _push(stack_t **stack, unsigned int line)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		free_all(node);
		exit(EXIT_FAILURE);
	}

	if (!b.key && b.key != 0)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
		free_all((*stack));
		free(node);
		exit(EXIT_FAILURE);
	}

	if (b.key)
	{
		if (b.key[0] == '-')
			node->n = atoi(b.key) * -1;
		else
			node->n = atoi(b.key);
		node->next = *stack;
		node->prev = NULL;
		if (*stack)
			(*stack)->prev = node;
		*stack = node;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
		free_all((*stack));
		free(node);
		exit(EXIT_FAILURE);
	}
}

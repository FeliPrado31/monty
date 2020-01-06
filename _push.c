#include "monty.h"
/**
 * _push - adds a new element to the top of the stack
 * @stack: stack
 * @line: line number
 */

void _push(stack_t **stack, unsigned int line)
{
	stack_t *node;
	(void)line;
	node = malloc(sizeof(stack_t));
	/*if (node == NULL)
	{
		printf("Error: malloc failed\n");
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}*/

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
		node->prev = NULL;
		if (*stack != NULL)
		{
			(*stack)->prev = node;
			node->next = *stack;
		}
		else
			node->next = NULL;
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
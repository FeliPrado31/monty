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
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}

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
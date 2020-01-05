#include "monty.h"
/**
 * _pop - Funtionces of the opcode pop.
 * @head: Stack.
 * @line: line of the line where the opcode is taken.
 */
void _pop(stack_t **head, unsigned int line)
{
	stack_t *tmp = *head;

	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't pop an empty stack", line);
		free(head);
		exit(EXIT_FAILURE);
	}

	*head = tmp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(tmp);
}

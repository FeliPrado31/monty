#include "monty.h"

void _pop(stack_t **head, unsigned int line_number)
{
    stack_t *tmp = *head;

    if (head == NULL || *head == NULL)
    {
        printf("L%u: can't pop an empty stack", line_number);
        free(head);
        exit(EXIT_FAILURE);
    }

    *head = tmp->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(tmp);
}
#include "monty.h"


/**
 * 
 * 
 */

void _push(stack_t **head, unsigned int line_number)
{
    stack_t *push;
    (void) line_number;
    push = malloc(sizeof(stack_t));
    if (push == NULL)
    {
        printf("Error: malloc failed");
        free(push);
        exit(EXIT_FAILURE);
    }
    push->n = number;
    push->prev = NULL;
    if (*head != NULL)
    {
        (*head)->prev = push;
        push->next = *head;
    }
    else
        push->next = NULL;
    *head = push;
}

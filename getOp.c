#include "monty.h"
/**
 * getOp - getOp
 * @stack: stack_t stack
 * @counter: int counter
 * @code: char code
 */
void getOp(stack_t **stack, unsigned int counter, char *code)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if ((strcmp(op[i].opcode, code)) == 0)
		{
			op[i].f(stack, counter);
			break;
		}
		i++;
	}
	if (op[i].f == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", counter, code);
		exit(EXIT_FAILURE);
	}

}

/**
 * free_all - free_all.
 * @stack: stack_t stack.
 */
void free_all(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	fclose(b.f);
	free(b.stream);
}

#include "monty.h"

/**
 * _add - add the top element in the stack from the next top element
 * and replaces the top two nodes with the result
 * @stack: stack
 * @line: line number
 */

void _add(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += tmp->n;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * _sub - subtracts the top element in the stack from the next top element
 * and replaces the top two nodes with the result
 * @stack: stack
 * @line: line number
 */

void _sub(stack_t **stack, unsigned int line)
{
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line);
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}

	sub = ((*stack)->next)->n - (*stack)->n;

	_pop(stack, line);
	(*stack)->n = sub;
}

/**
 * _mul - multiplies the top two elements in the stack
 * and replaces both nodes with the product
 * @stack: stack
 * @line: line
 */

void _mul(stack_t **stack, unsigned int line)
{
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line);
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}

	mul = ((*stack)->next)->n * (*stack)->n;

	_pop(stack, line);
	(*stack)->n = mul;
}

/**
 * _div - divides the top of the stack by the next element in the stack
 * and replaces the top two nodes in the stack by the dividend
 * @stack: stack
 * @line: line number
 */

void _div(stack_t **stack, unsigned int line)
{
	int div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line);
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line);
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;

	_pop(stack, line);
	(*stack)->n = div;
}
/**
 * _mod - finds the remainder when the top element in the stack is divided by
 * the next element and replaces both nodes with that result
 * @stack: stack
 * @line: line number
 */

void _mod(stack_t **stack, unsigned int line)
{
	int mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line);
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line);
		free_all(*(stack));
		free(stack);
		exit(EXIT_FAILURE);
	}

	mod = ((*stack)->next)->n % (*stack)->n;

	(*stack)->next->n = mod;
	_pop(stack, line);
}

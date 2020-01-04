#include "monty.h"

int _strncmp(char *s1, char *s2, int len)
{
	int i = 0;

	while (s1[i] && i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	return (1);
}

/**
 * 
 */
int getLen(char *code)
{
	int i, len;

	while (isalpha(code[i]))
	{
		++len;
		++i;
	}
	return (len);
}
/**
 * 
 */
void (*get_func(char *code))(stack_t **stack, unsigned int line_number)
{
	int i, len;

	instruction_t ins[] = {
		{"push", _push},
		{"nop", _nop},
		{"pop", _pop},
		{NULL, NULL}};

	len = getLen(code);
	for (i = 0; ins[i].opcode != NULL; i++)
	{
		if (_strncmp(code, ins[i].opcode, len))
			return (ins[i].f);
	}
	return (ins[i].f);
}

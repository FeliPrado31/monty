#include "monty.h"
gBuff b = {NULL, NULL, NULL};

/**
 * parseFile - parseFile
 * @code: char code
 * @stack: stack_t stack
 * @line: int line
 */
void parseFile(char *code, stack_t **stack, unsigned int line)
{
	char *str, *token;

	str = strtok(code, " \n\t");
	token = strtok(NULL, " \n\t");
	b.key = token;
	if (str && str[0] != '#')
		getOp(stack, line, str);
}

/**
 * readFile - readFile
 * @file: char file
 */
void readFile(char *file)
{

	struct stat Stat;
	int check;
	unsigned int i = 0;
	ssize_t chr;
	size_t size = 0;
	stack_t *stack = NULL;

	check = stat(file, &Stat);
	if (check == 0)
	{
		if (!checkFile(file))
		{
			fprintf(stderr, "Error: Can't open file %s\n", file);
			free(stack);
			exit(EXIT_FAILURE);
		}
	}
	b.f = fopen(file, "r");
	if (!b.f)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while ((chr = getline(&b.stream, &size, b.f)) != EOF)
	{
		i++;
		parseFile(b.stream, &stack, i);
	}
	free_all(stack);
	exit(EXIT_SUCCESS);
}

/**
 * checkFile - read the content of a monty file.
 * @file: The file  to a file
 * Return: Always 0.
 */
int checkFile(char *file)
{
	int len = strlen(file);

	len--;
	if (file[len - 1] == '.' && file[len] == 'm')
		return (1);
	return (0);
}

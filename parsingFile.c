#include "monty.h"
/* MACROS */
#define MAX 1024
int number;
/**
 *
 */

void open_file(char *file)
{
	/** 
     * TODO:
	 * create stream for token
	 * and tokenizing
	 */
	int lines;
	char *stream, *token;
	stack_t **stack;

	stack = malloc(sizeof(char *));
	if (stack == NULL)
	{
		/**
		 * TODO:
		 * print error message
		 */
		exit(EXIT_FAILURE);
	}

	stream = read_file(file);
	/* strtok for tokenizing */
	token = strtok(stream, "\n");
	/*  */
	while (token)
	{
		/* Search op*/
		search_op(stack, lines, token);
		++lines;
		token = strtok(NULL, "\n");
	}
	free(stack);
}


/**
 * 
 */
int isNumber(char *code)
{
	int i = 0, isSpace = 0;

	if (code[i] == ' ')
		i++;
	while (code[i] == '\0')
	{
		if (code[i] == ' ')
		{
			if ((code[i] < '0' || code[i] > '9') && code[i] != '-')
				return (-1);
			isSpace = 1;
		}
		else
		{
			if (isSpace == 1)
				return (0);
		}
		i++;
	}
	if (isSpace == 0)
		return (-1);
	return (0);
}

/**
 * 
 */
void search_op(stack_t **stack, int lines, char *token)
{
	/* Check if the func is push or not*/
	void (*f)(stack_t * *stack, unsigned int line_number);

	/* check if have space */
	while (isspace(*token))
		token++;
	if (token[0] == '#')
		return;
	/* check if the func is push */
	if (strncmp(token, "push ", 5))
	{
		/* check if start with a letter */
		while (isalpha(*token))
			token++;
		/* func to check if is a number or not */
		if (isNumber(token) == -1)
		{
			/**
			 * TODO:
			 * print error message and free stack
			 */
			free(stack);
			exit(EXIT_FAILURE);
		}
		if (token[0] == '-')
			number = atoi(token) * -1;
		else
			number = atoi(token);
		token = "push";
	}
	f = get_func(token);
	if (f == NULL)
	{
		/**
		 * TODO:
		 * print error message
		 */
		free(stack);
		exit(EXIT_FAILURE);
	}
	f(stack, lines);
}

/**
 * 
 */
char *read_file(char *file)
{
	/** 
     * TODO:
	 * If, for any reason,
	 * it’s not possible to open the file,
	 * print the error message Error: Can't open file <file>,
	 * followed by a new line,
	 * and exit with the status EXIT_FAILURE
	 */
	FILE *newFile;
	char buff[MAX + 1];
	char *buff_end;
	size_t len = 0;

	newFile = fopen(file, "r");
	if (newFile)
	{
		/* storage all lines inside len*/
		len = fread(buff, sizeof(char), MAX, newFile);
		/* if error exit failure */
		if (ferror(newFile) != 0)
		{
			/* print error message */
			printf("Error file");
			exit(EXIT_FAILURE);
		}
		/* add null */
		else
			buff[len++] = '\0';
	}
	else
	{
		/* code */
		printf("Can't open file");
		exit(EXIT_FAILURE);
	}
	buff_end = buff;
	fclose(newFile);
	return (buff_end);
}

#ifndef _MONTY_
#define _MONTY_

extern int number;

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main.c */


/* parse_file.c */
void open_file(char *file);
char *read_file(char *file);
void search_op(stack_t **stack, int lines, char *token);
int isNumber(char *str);


/* get_func.c */
void (*get_func(char *code))(stack_t **stack, unsigned int line_number);
int getLen(char *code);
int _strncmp(char *s1, char *s2, int len);


/* _nop.c */
void _nop(stack_t **stack, unsigned int line_number);

/* push.c */
void _push(stack_t **head, unsigned int line_number);

/* _pop.c */
void _pop(stack_t **head, unsigned int line_number);

#endif

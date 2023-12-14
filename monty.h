#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

char *_strdup(char *);

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/*this is the head of the stack*/
extern stack_t *head;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_stack(stack_t **head);

/*dm functions*/
int pall(stack_t **stack, unsigned int line_number);
int pint(stack_t **stack, unsigned int line_number);
int pop(stack_t **stack, unsigned int line_number);
int swap(stack_t **stack, unsigned int line_number);
int add(stack_t **stack, unsigned int line_number);
int nop(stack_t **stack, unsigned int line_number);
int sub(stack_t **stack, unsigned int line_number);
int diva(stack_t **stack, unsigned int line_number);

extern instruction_t opcodes[];

#endif /* MONTY_H */

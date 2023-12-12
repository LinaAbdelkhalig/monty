#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from top
 * @head: a pointer to the head of the stack
 * @line_number: the number of the current line
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	(void)line_number;

	while (current->next)
		current = current->next;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}

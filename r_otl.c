#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @head: pointer to the top element in the stack
 * @line_number: the number of the current line
 * Decription: the top element of the stack becomes the last one,
 *		and the second top element becomes the first one
 * Return: 0
 */

int rotl(stack_t **head, unsigned int line_number)
{
	stack_t *old_top = *head, *new_top;

	(void)line_number;

	if (!head || !old_top || !old_top->next)
		return (0);

	new_top = old_top->next;
	*head = new_top;

	while (old_top->next)
		old_top = old_top->next;
	old_top->next = new_top->prev;
	new_top->prev = NULL;
	old_top->next->prev = old_top;
	old_top->next->next = NULL;

	return (0);
}

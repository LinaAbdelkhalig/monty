#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @head: pointer to the top element in the stack
 * @line_number: the number of the current line
 * Decription: the last element of the stack becomes the top one,
 * Return: 0
 */

int rotr(stack_t **head, unsigned int line_number)
{
	stack_t *new_top = *head, *old_top = *head;

	(void)line_number;

	if (!head || !old_top || !old_top->next)
		return (0);

	while (new_top->next)
	{
		new_top = new_top->next;
	}

	new_top->prev->next = NULL;
	*head = new_top;
	new_top->prev = NULL;
	new_top->next = old_top;
	old_top->prev = new_top;

	return (0);
}

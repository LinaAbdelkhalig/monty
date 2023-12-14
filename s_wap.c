#include "monty.h"

/**
 * swap - swaps the top two elements in the stack
 * @head: pointer to the head of the stack
 * @line_number: the number of the line
 * Return: 0 or -1 if fail
 */

int swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *current = *head;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (-1);
	}
	temp = current->next;
	current->next = temp->next;
	temp->prev = NULL;
	current->prev = temp;
	temp->next = current;

	if (current->next)
		current->next->prev = current;
	*head = temp;
	return (0);
}

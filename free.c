#include "monty.h"

/**
 * free_stack - frees the whole stack after done with it
 * @head: pointer to the head of the stack
 */
void free_stack(stack_t **head)
{
	stack_t *current = *head, *temp;

	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}

	*head = NULL;
}

#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: pointer to the top element in the stack
 * @line_number: the number of the current line
 * Return: 0 or -1 if fail
 */

int pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (temp)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return (-1);
	}
	return (0);
}

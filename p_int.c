#include "monty.h"

/**
 * pint - prints the value at the top of the stack and \n
 * @head: pointer to the head of the stack
 * @line_number: the number of the current line
 * Return: 0, if empty return -1
 */

int pint(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current)
		printf("%d\n", current->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (-1);
	}
	return (0);
}

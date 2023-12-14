#include "monty.h"

/**
 * pchar - prints the value at the top of the stack a ascii value
 * @head: pointer to the head of the stack
 * @line_number: the number of the current line
 * Return: 0, if empty return -1
 */

int pchar(stack_t **head, unsigned int line_number)
{
	stack_t *h = *head;

	if (h)
	{
		if ((h->n >= 65 && h->n <= 90) || (h->n >= 97 && h->n <= 122))
			printf("%c\n", (char)h->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			return (-1);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		return (-1);
	}
	return (0);
}

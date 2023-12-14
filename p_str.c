#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @head: pointer to the head of the stack
 * @line_number: the number of the current line
 * Return: 0, if empty return -1
 */

int pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h = *head;

	(void)line_number;

	while (h && h->n != 0)
	{
		/*if ((h->n == 0) || (h->n < 65 && h->n > 90) || (h->n < 97 && h->n > 122))*/
		if ((h->n == 0) || (h->n < 65 && h->n > 90) || (h->n < 97 && h->n > 122))
		{
			printf("\n");
			return (0);
		}
		printf("%c", (char)h->n);
		h = h->next;
	}
	printf("\n");
	return (0);
}

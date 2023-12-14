#include "monty.h"

/**
 * mod - computes the mod of the two top elements in the stack
 * @head: the pointer to the head of the stack
 * @line_number: the number of the line
 * Return: 0 or -1 if fail
 */

int mod(stack_t **head, unsigned int line_number)
{
	stack_t *denum = *head;
	int res;

	if (!denum || !denum->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		return (-1);
	}
	if (denum->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		return (-1);
	}
	res = denum->next->n % denum->n;
	denum->next->n = res;
	*head = denum->next;
	free(denum);
	return (0);
}

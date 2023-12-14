#include "monty.h"

/**
 * sub - subtracts the two top elements in the stack
 * @head: the pointer to the head of the stack
 * @line_number: the number of the line
 * Return: 0 or -1 if fail
 */

int sub(stack_t **head, unsigned int line_number)
{
	stack_t *lina = *head;
	int res;

	if (!lina || !lina->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		return (-1);
	}
	res = lina->next->n - lina->n;
	lina->next->n = res;
	*head = lina->next;
	free(lina);
	return (0);
}

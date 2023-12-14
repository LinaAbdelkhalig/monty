#include "monty.h"

/**
 * mul - multiplies the two top elements in the stack
 * @head: the pointer to the head of the stack
 * @line_number: the number of the line
 * Return: 0 or -1 if fail
 */

int mul(stack_t **head, unsigned int line_number)
{
	stack_t *nafisa = *head;
	int res;

	if (!nafisa || !nafisa->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		return (-1);
	}
	res = nafisa->n * nafisa->next->n;
	nafisa->next->n = res;
	*head = nafisa->next;
	free(nafisa);
	return (0);
}

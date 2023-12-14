#include "monty.h"

/**
 * is_int - checks if the argument is an integer
 * @argument: the string to be checked
 * Return: 0 if its not valid int and 1 if its valid
 */

int is_int(char *argument)
{
	int i = 0;

	if (argument[0] == '-' || argument[0] == '+')
		i = 1;
	for (; argument[i] != '\0'; i++)
		if (!isdigit(argument[i]))
			return (0);
	return (1);
}

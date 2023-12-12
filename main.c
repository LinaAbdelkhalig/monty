#include "monty.h"

/**
 * push - pushes argument onto the stack
 * @argument: the argument to be pushed
 * @head: pointer to the head of the stack
 *
 * Return: void
 */
void push(stack_t **head, int argument)
{
	stack_t *current, *new_node = malloc(sizeof(stack_t));

	if (!new_node)
		fprintf(stderr, "Error: malloc failed");

	new_node->n = argument;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

/**
 * check_command - checks if the command is a valid instruction or not
 * @opc: the command
 * @head: pointer to the head of the stack
 * @line_num: the line number
 *
 * Return: 0 if valid instruction, -2 if invalid
 */
int check_command(char *opc, stack_t **head, unsigned int line_num)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pall", pall},
		/*
		 * {"pint", pint},
		 * {"pop", pop},
		 * {"swap", swap},
		 * {"add", add},
		 * {"nop", nop},
		 */
		{NULL, NULL}
	};

	while (opcodes[i].opcode != NULL)
	{
		if (strncmp(opcodes[i].opcode, opc, strlen(opcodes[i].opcode)) == 0)
		{
			opcodes[i].f(head, line_num);
			return (0);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opc);
	return (-2);
}

/**
 * check_line - checks if the line is valid or not
 * @line: the line to be checked
 * @head: pointer to the head of the stack
 * @n: the line number
 *
 * Description: checks if the line is a valid instruction or not,
 *		if valid it calls the function that does the job
 *		if invalid it returns -1
 *
 * Return: -2 if the line is invalid, -3 if malloc error, elsewise 0
 */
int check_line(char *line, stack_t **head, ssize_t n)
{
	char *opcode, *argument, *linecpy;

	/*skip all the spaces in the beginning*/
	while (isspace(*line))
		line++;
	if (*line == '\0') /*if the line is empty*/
		return (0);
	/*copy the line to tokenise it, if unable to strdup error*/
	linecpy = _strdup(line);
	if (!linecpy)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-2); }
	/*tokenise to get the command*/
	opcode = strtok(linecpy, " ");
	if (!opcode)
	{
		free(linecpy);
		return (-1); }
	if (strcmp(opcode, "push") == 0)
	{
		/*tokenise again to get the argument*/
		argument = strtok(NULL, " ");
		if (!argument)
		{
			free(linecpy);
			return (-1); }
		if (atoi(argument) == 0 && strncmp(argument, "0", 1) != 0)
		{
			fprintf(stderr, "L%ld: usage: push integer\n", n);
			free(linecpy);
			return (-2); }
		push(head, atoi(argument)); }
	else
	{
		check_command(opcode, head, n);
		free(linecpy);
		return (0); }
	free(linecpy);
	return (0);
}

/**
 * read_file - reads the monty file
 * @filename: the name of the monty file to be read
 *
 * Return: the number of lines read
 *	- If the file can not be opened or read, return -1
 *	- If the file contains invalid instructions, return -2
 *	- If malloc error, return -3
 */
ssize_t read_file(const char *filename)
{
	stack_t *head = NULL;
	int checker; /*return of check_line "malloc, invalid op,..."*/
	ssize_t read_count = 0; /*number of read lines*/
	char line[256];
	FILE *fptr; /*pointer to the beginning of the file*/

	/*open filename as readonly, if not opened return -1*/
	fptr = fopen(filename, "r");
	if (!fptr)
		return (-1);

	/*go through each line of the file*/
	while (fgets(line, sizeof(line), fptr))
	{
		read_count++;
		checker = check_line(line, &head, read_count);
		if (checker == -2 || checker == -3)
		{
			fclose(fptr);
			return (checker);
		}
	}

	/*if an error occured during the reading, close and return 0*/
	if (ferror(fptr))
	{
		fprintf(stderr, "Error: Failed to read the file\n");
		fclose(fptr);
		return (0);
	}

	fclose(fptr);
	return (read_count);
}

/**
 * main - does shit
 * @argc: argument count
 * @argv: argument vetor
 *
 * Return: 0 if success, EXIT_FAILURE if failed
 */
int main(int argc, char **argv)
{
	ssize_t n;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	n = read_file(argv[1]);
	if (n == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (n == -2 || n == -3)
		exit(EXIT_FAILURE);

	return (0);
}

#include "monty.h"

stack_t *head = NULL;

/**
 * push - pushes argument onto the stack
 * @argument: the argument to be pushed
 * Return: void
 */

void push(int argument)
{
	stack_t *current, *new_node = malloc(sizeof(stack_t));

	if (!new_node)
		fprintf(stderr, "Error: malloc failed");

	new_node->n = argument;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current = head;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}
void pall(void)
{
	stack_t *current = head;

	if (head)
	{
		while(current)
			current = current->next;
		while(current)
		{
			printf("%d\n", current->n);
			current = current->prev;
		}
	}
	printf("no stack");
}
/**
 * check_command - checks if the command is a valid instruction or not
 * @opcode: the command
 * @line_num: the line number
 *
 * Return: 0 if valid instruction, -2 if invalid
 */
/*
int check_command(char *opcode, unsigned int line_num)
{
	stack_t *stack;
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_num);
			return (0);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	return (-2);
}*/

/**
 * check_line - checks if the line is valid or not
 * @line: the line to be checked
 * @n: the line number
 *
 * Description: checks if the line is a valid instruction or not,
 *		if valid it calls the function that does the job
 *		if invalid it returns -1
 *
 * Return: -2 if the line is invalid, -3 if malloc error, elsewise 0
 */
int check_line(char *line, ssize_t n)
{
	char *opcode, *argument, *linecpy;

	printf("checking line %ld: \n", n);
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
		push(atoi(argument)); }
	pall();
	/*else
	{
		free(linecpy);
		return (check_command(opcode, n)); }*/
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
		checker = check_line(line, read_count);
		if (checker == -2 || checker == -3)
		{
			fclose(fptr);
			return (checker);
		}
		printf("%s.", line);
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

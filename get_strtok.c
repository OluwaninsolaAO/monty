#include "monty.h"

/**
 * get_strtok - tokenizes a line
 * @line: line to be tokenised
 * @line_number: line number of the line to be tokenised
 * Return: token
 */
char *get_strtok(char *line, unsigned int line_number)
{
	char *delim = " ";
	char *token = NULL;
	char *arg = NULL;

	line = strtok(line, "\n");
	token = strtok(line, delim);

	if (!token) /*empty lines*/
		return (NULL);

	if (token[0] == '#') /*comments*/
		return (NULL);

	arg = strtok(NULL, delim);
	if (arg)
	{
		if (check_if_integer(arg))
		{
			global_var = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else if (arg == NULL && (strcmp(token, "push") == 0))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
		exit(EXIT_FAILURE);
	}
	return (token);
}

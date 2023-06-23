#include "monty.h"

/**
 * execute_instructions - Executes Monty instructions from a file
 * @file: pointer of the input file
 */
void execute_instructions(FILE *file)
{
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char line[1024];
	char *opcode;
	char *trimmed_line;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;

		trimmed_line = line;
		while (isspace(*trimmed_line))
			trimmed_line++;

		if (*trimmed_line == '\0' || *trimmed_line == '#')
			continue;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		process_opcode(&stack, line_number, opcode);
	}

	free_stack(stack);
}

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: EXIT_SUCCESS in success case, EXIT_FAILURE on failure case.
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_instructions(file);

	fclose(file);
	exit(EXIT_SUCCESS);
}

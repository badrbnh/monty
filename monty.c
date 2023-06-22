#include "monty.h"
#include <ctype.h>

/**
 * execute_instructions - Executes Monty instructions from a file
 * @file: Pointer to the input file
 */
void execute_instructions(FILE *file)
{
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instruction;
	char line[1024];
	char *opcode;
	char *end;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = line;

		while (isspace(*opcode))
			opcode++;

		if (*opcode == '\0' || *opcode == '#')
			continue;

		end = opcode + strlen(opcode) - 1;
		while (end > opcode && isspace(*end))
			end--;
		*(end + 1) = '\0';

		instruction.opcode = strtok(opcode, " \t\n");

		if (instruction.opcode == NULL)
		{
			fprintf(stderr, "L%d: missing opcode\n", line_number);
			exit(EXIT_FAILURE);
		}

		if (strcmp(instruction.opcode, "push") == 0)
			instruction.f = push;
		else if (strcmp(instruction.opcode, "pall") == 0)
			instruction.f = pall;
		else if (strcmp(instruction.opcode, "pop") == 0)
			instruction.f = pop;
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, instruction.opcode);
			exit(EXIT_FAILURE);
		}

		instruction.f(&stack, line_number);
	}

	free_stack(stack);
}

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
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

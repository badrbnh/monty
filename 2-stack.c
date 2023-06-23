#include "monty.h"


void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = top->next;

	next->n *= top->n;

	*stack = next;
	next->prev = NULL;
	free(top);
}
/**
 * _mod - Computes the rest of the division of the second top element
 *        of the stack by the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	next->n %= top->n;

	*stack = next;
	next->prev = NULL;
	free(top);
}
/**
 * pchar - Prints the char at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL && current->n != 0 && current->n >= 0 &&
	current->n <= 127)
	{
		putchar(current->n);

		current = current->next;
	}

	putchar('\n');
}
/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *last = *stack;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	*stack = top->next;
	(*stack)->prev = NULL;

	last->next = top;
	top->prev = last;
	top->next = NULL;
}


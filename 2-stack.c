#include "monty.h"
/**
 * _mul - Multiplies the second top element of the stack with the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
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

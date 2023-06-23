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

#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = top->next;

	top->next = next->next;
	top->prev = next;
	next->next = top;
	next->prev = NULL;

	*stack = next;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = top->next;

	next->n += top->n;

	*stack = next;
	free(top);
}

/**
 * nop - Doesn't do anything.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* No operation */
	(void)stack;
	(void)line_number;
}

/**
 * sub - substract two top element
 * @stack: pointer to stack
 * @line_number: line's number
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = (*stack)->next;
	next->n -= top->n;

	*stack = next;
	top->next = NULL;
	free(top);
}

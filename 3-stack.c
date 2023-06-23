#include "monty.h"
/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

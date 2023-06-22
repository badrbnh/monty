#include "monty.h"


/**
 * sub_op - substract two top element
 * @s: pointer to stack
 * @ln: line's number
 */

void sub_op(stack_t **s, unsigned int ln)
{
	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln)
			end_app();
	}

	stack_t *curr = *s;
	stack_t *prev = (*s)->next;
	prev->n -= curr->n;
	
	*s = prev;
	curr->next = NULL;
	free(curr);
}


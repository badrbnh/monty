#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Macros */
#define LIMIT 4

/* Structures */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void pop(stack_t **stack, unsigned int line_number);

#endif
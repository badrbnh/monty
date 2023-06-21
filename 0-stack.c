#include "lib.h"

int pop()
{
    int value;
    if (top == -1)
    {
        fprintf(stderr, "Stack Underflow\n");
        exit(1);
    }
    value = stack_arr[top];
    top--;
    return value;
}

void push(int data)
{
    if (top == LIMIT - 1)
    {
        fprintf(stderr, "Stack Overflow\n");
        return;
    }
    top++;
    stack_arr[top] = data;
}

void pall()
{
    int i;

    if (top == -1)
    {
        fprintf(stderr, "Stack Underflow\n");
        return;
    }
    for (i = top; i >= 0; i--)
    {
        fprintf(stdout, "%d ", stack_arr[i]);
    }
    fprintf(stdout, "\n");
}

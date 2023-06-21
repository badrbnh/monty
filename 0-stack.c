#include "lib.h"

int stack_arr[LIMIT];
int top = -1;

int pop()
{
    int value;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    value = stack_arr[top];
    top--;
    return (value);

}

void push(int data)
{
    if (top == LIMIT -1)
    {
        printf("Stack Overflow\n");
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
        printf("Stack Underflow\n");
        return;
    }
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack_arr[i]);
        printf("\n");
    }
}

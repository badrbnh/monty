#include "monty.h"

struct node
{
    struct node *link;
    int data;

   
} *top = NULL;


void push(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(newNode));
    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        exit(1);
    }

    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
}

void print()
{
    struct node *temp;
    temp = top;
    while(temp)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}

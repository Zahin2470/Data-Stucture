#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int digit)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    newNode->data = digit;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        exit(1);
    }
    struct Node *temp = top;
    int digit = temp->data;
    top = top->next;
    free(temp);
    return digit;
}

void decimalToBinary(int decimal)
{
    if (decimal == 0)
    {
        push(0);
    }
    else
    {
        while (decimal > 0)
        {
            push(decimal % 2);
            decimal = decimal / 2;
        }
    }
}

int main()
{
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    printf("Binary representation: ");
    while (top != NULL)
    {
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}
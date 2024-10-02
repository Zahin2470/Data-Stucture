#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *top = NULL;

void push(char ch)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
    {
        printf("Closing parentheses not matched.\n");
        exit(1);
    }
    struct Node *temp = top;
    char ch = temp->data;
    top = top->next;
    free(temp);
    return ch;
}

int parentheses(char *expression)
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            push('(');
        }
        else if (expression[i] == ')')
        {
            if (top == NULL)
            {
                printf("Closing parentheses not matched\n");
                return 0;
            }
            pop();
        }
    }

    if (top != NULL)
    {
        printf("Opening parentheses not matched\n");
        return 0;
    }

    return 1;
}

int main()
{
    char expression[100];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (parentheses(expression))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid.\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};
struct Node *top = 0;

void push()
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Stack is Empty");
        return;
    }
    printf("Enter value to push : ");
    scanf("%d", &newnode->value);

    newnode->next = top;
    top = newnode;
    printf("Data pushed the stack \n");
}

void print()
{
    struct Node *current = top;
    printf("Stack Elements : ");
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is Empty");
        return;
    }
    struct Node *temp = top;
    printf("%d", temp->value);
    top = top->next;
    free(temp);
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.Push Stack \n");
        printf("2.Print Stack \n");
        printf("3.Pop Stack \n");
        printf("0. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            push();
        }
        else if (choice == 2)
        {
            print();
        }
        else if (choice == 3)
        {
            pop();
        }
        else
        {
            printf("Invalid choice, Please try again.\n");
        }
        print();
    }
}
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Define a structure for a stack
struct Stack {
    char data;
    struct Stack* next;
};

// Function to create a new node for the stack
struct Stack* createNode(char data) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a character onto the stack
void push(struct Stack** top, char data) {
    struct Stack* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a character from the stack
char pop(struct Stack** top) {
    if (*top == NULL) {
        return '\0'; // Empty stack
    }

    char data = (*top)->data;
    struct Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to check if the expression has correct pairs and orders of brackets
int isBalanced(char bracket[]) {
    int len = strlen(bracket);
    struct Stack* stack = NULL;

    for (int i = 0; i < len; i++) {
        char currentChar = bracket[i];

        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            push(&stack, currentChar);
        } 
        else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
            char poppedChar = pop(&stack);

            // Check if the popped character matches the corresponding opening character
            if ((currentChar == ')' && poppedChar != '(') ||
                (currentChar == '}' && poppedChar != '{') ||
                (currentChar == ']' && poppedChar != '[')) {
                return 0; // Unbalanced
            }
        }
    }

    // If the stack is empty, the expression is balanced
    return stack == NULL;
}

// Main function to test the isBalanced function
int main() {
    // Test cases
    char exp1[] = "{[()]}";
    char exp2[] = "{[(])}";
    char exp3[] = "((()))";
    char exp4[] = "(()";

    printf("%s is %sbalanced.\n", exp1, isBalanced(exp1) ? "" : "not ");
    printf("%s is %sbalanced.\n", exp2, isBalanced(exp2) ? "" : "not ");
    printf("%s is %sbalanced.\n", exp3, isBalanced(exp3) ? "" : "not ");
    printf("%s is %sbalanced.\n", exp4, isBalanced(exp4) ? "" : "not ");

    return 0;
}

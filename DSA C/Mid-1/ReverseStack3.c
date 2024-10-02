#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to print the reverse of individual words in a string
void reverseWords(char* str) {
    int len = strlen(str);
    struct Stack* stack = NULL;

    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            push(&stack, str[i]);
        } else {
            while (stack != NULL) {
                printf("%c", pop(&stack));
            }
            printf(" ");
        }
    }

    // Print the last word
    while (stack != NULL) {
        printf("%c", pop(&stack));
    }

    printf("\n");
}

// Main function to test the reverseWords function
int main() {
    char str[] = "Hello World";
    
    printf("Original String: %s\n", str);
    printf("Reverse of Individual Words: ");
    reverseWords(str);

    return 0;
}

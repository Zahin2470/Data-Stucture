#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find the middle of the linked list
void middleList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    int count = 0;

    // Traverse the linked list to find its length
    while (head != NULL) {
        // Move temp only when the count is odd
        if (count % 2 == 1) {
            temp = temp->next;
        }

        head = head->next;
        count++;
    }

    // If the count is even, temp is at the middle of the list
    printf("The middle of the linked list is: %d\n", temp->data);
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the middleList function
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printf("Original Linked List: ");
    printList(head);

    // Find and print the middle of the linked list
    middleList(head);

    return 0;
}
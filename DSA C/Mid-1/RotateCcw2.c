#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void appendNode(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to rotate the doubly linked list counter-clockwise by N nodes
void rotateList(struct Node **head, int N)
{
    if (*head == NULL || N <= 0)
    {
        printf("Invalid input. Rotation not possible.\n");
        return;
    }

    // Find the length of the doubly linked list
    int length = 0;
    struct Node *temp = *head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    // Ensure N is within the valid range
    N = N % length;

    if (N == 0)
    {
        printf("No rotation needed. List remains unchanged.\n");
        return;
    }

    // Move to the (length - N)th node
    temp = *head;
    for (int i = 1; i < length - N; i++)
    {
        temp = temp->next;
    }

    // Adjust pointers to rotate the list
    struct Node *newHead = temp->next;
    newHead->prev = NULL;
    temp->next = NULL;

    // Move to the last node of the original list
    temp = newHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Connect the last node to the original head
    temp->next = *head;
    (*head)->prev = temp;

    // Update the head pointer to the new head
    *head = newHead;
}

// Function to print the doubly linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the rotateList function
int main()
{
    struct Node *head = NULL;

    // Create a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Original Doubly Linked List: ");
    printList(head);

    // Rotate the list counter-clockwise by 2 nodes
    rotateList(&head, 2);

    printf("Doubly Linked List after rotating by 2 nodes: ");
    printList(head);

    return 0;
}
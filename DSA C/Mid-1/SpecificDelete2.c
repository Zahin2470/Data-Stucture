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

// Function to delete all occurrences of a key from the doubly linked list
void deleteOccurrences(struct Node **head, int x)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *current = *head;
    struct Node *nextNode = NULL;

    // Traverse the list and delete nodes with the specified key
    while (current != NULL)
    {
        nextNode = current->next;

        // Check if the current node has the key to be deleted
        if (current->data == x)
        {
            // Update pointers to skip the current node
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                *head = current->next;
            }

            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }

            // Free the memory of the current node
            free(current);
        }

        // Move to the next node
        current = nextNode;
    }
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

// Main function to test the deleteOccurrences function
int main()
{
    struct Node *head = NULL;

    // Create a sample doubly linked list: 1 <-> 2 <-> 3 <-> 2 <-> 4 <-> 2
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 2);
    appendNode(&head, 4);
    appendNode(&head, 2);

    printf("Original Doubly Linked List: ");
    printList(head);

    // Delete all occurrences of key 2
    int keyToDelete = 2;
    deleteOccurrences(&head, keyToDelete);

    printf("Doubly Linked List after deleting occurrences of %d: ", keyToDelete);
    printList(head);

    return 0;
}
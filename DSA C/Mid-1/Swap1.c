#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to swap nodes with keys key1 and key2
void swapNodes(struct Node **head, int key1, int key2)
{
    // If both keys are the same, no need to swap
    if (key1 == key2)
    {
        printf("Keys are the same. No swapping needed.\n");
        return;
    }

    // Initialize pointers to track the nodes with key1 and key2
    struct Node *prev1 = NULL, *curr1 = *head;
    struct Node *prev2 = NULL, *curr2 = *head;

    // Find the nodes with key1 and key2 and keep track of their predecessors
    while (curr1 != NULL && curr1->data != key1)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    while (curr2 != NULL && curr2->data != key2)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    // If either key is not present, no swapping is possible
    if (curr1 == NULL || curr2 == NULL)
    {
        printf("One or both keys not present. No swapping possible.\n");
        return;
    }

    // If key1 is not the head of the list, update the predecessor of key1
    if (prev1 != NULL)
    {
        prev1->next = curr2;
    }
    else
    {
        *head = curr2;
    }

    // If key2 is not the head of the list, update the predecessor of key2
    if (prev2 != NULL)
    {
        prev2->next = curr1;
    }
    else
    {
        *head = curr1;
    }

    // Swap the next pointers of the nodes with key1 and key2
    struct Node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the swapNodes function
int main()
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original Linked List: ");
    printList(head);

    // Swap nodes with keys 2 and 4
    swapNodes(&head, 2, 4);

    printf("Linked List after swapping nodes 2 and 4: ");
    printList(head);

    // Swap nodes with keys 1 and 5
    swapNodes(&head, 1, 5);

    printf("Linked List after swapping nodes 1 and 5: ");
    printList(head);

    // Swap nodes with the same key (no actual swap should occur)
    swapNodes(&head, 3, 3);

    printf("Linked List after swapping nodes with the same key: ");
    printList(head);

    return 0;
}
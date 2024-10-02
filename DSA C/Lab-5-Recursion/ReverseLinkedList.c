#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void diplay(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* createLinkedList() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter data for node ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct Node* reverseList(struct Node* current, struct Node* prev) {
    if (current == NULL) {
        return prev;
    }

    struct Node* nextNode = current->next;
    current->next = prev;

    return reverseList(nextNode, current);
}
struct Node* reverseLinkedList(struct Node* head) {
    return reverseList(head, NULL);
}

int main() {
    
    struct Node* head = createLinkedList();

    printf("Original Linked List: ");
    diplay(head);

    head = reverseLinkedList(head);

    printf("Reversed Linked List: ");
    diplay(head);

    return 0;
}
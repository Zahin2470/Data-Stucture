#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* unionLists(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;

    while (head1 != NULL) {
        insertNode(&result, head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL) {

        struct Node* curr = result;
        int c = 0;
        while (curr != NULL) {
            if (curr->data == head2->data) {
                c = 1;
                break;
            }
            curr = curr->next;
        }
        if (!c) {
            insertNode(&result, head2->data);
        }
        head2 = head2->next;
    }
    return result;
}

void newList(struct Node* head) {
    struct Node* curr = head;
    struct Node* nextNode;

    while (curr != NULL) {
        nextNode = curr->next;
        free(curr);
        curr = nextNode; }
}

int main() {

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    insertNode(&head1, 20);
    insertNode(&head1, 15);
    insertNode(&head1, 10);
    insertNode(&head1, 30);
    insertNode(&head1, 60);

    insertNode(&head2, 20);
    insertNode(&head2, 5);
    insertNode(&head2, 30);
    insertNode(&head2, 35);
    insertNode(&head2, 60);
    insertNode(&head2, 70);
    insertNode(&head2, 90);

    printf("Here List1: ");
    printList(head1);
    printf("Here List2: ");
    printList(head2);

    struct Node* result = unionLists(head1, head2);

    printf("List3: ");
    printList(result);

    newList(head1);
    newList(head2);
    newList(result);

    return 0;
}
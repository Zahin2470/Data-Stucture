#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void create(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertBegin(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertElement(int value, int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(newNode);
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertEnd(int value)
{
    struct Node *newnode; 
    struct Node *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &newnode->value);
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void deleteBegin()
{
    if (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }

    free(tail);
    tail = temp;
    tail->next = NULL;
}

void deleteElement(int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        deleteBegin();
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of range\n");
    }
    else
    {
        struct Node *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}

void reverseLinkedList()
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}
void removeDuplicates()
{
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *prev = current;
        struct Node *next = current->next;

        while (next != NULL)
        {
            if (next->value == current->value)
            {
                prev->next = next->next;
                free(next);
                next = prev->next;
            }
            else
            {
                prev = next;
                next = next->next;
            }
        }

        current = current->next;
    }
}

void display()
{
    struct Node *current = head;
    printf("\nLinked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Insert new node\n");
        printf("2. Insert node at beginning\n");
        printf("3. Insert node at any position\n");
        printf("4. Insert node at ending\n");
        printf("5. Delete Node from beginning\n");
        printf("6. Delete Node from last position\n");
        printf("7. Delete Node from any position\n");
        printf("8. Reverse Linked list\n");
        printf("9. Remove Duplicate data from Linked list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int x;
            printf("Enter the value: ");
            scanf("%d", &x);
            create(x);
        }
        else if (choice == 2)
        {
            int x;
            printf("Enter the value: ");
            scanf("%d", &x);
            insertBegin(x);
        }
        else if (choice == 3)
        {
            int val, pos;
            printf("Enter the value: ");
            scanf("%d", &val);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insertElement(val, pos);
        }
        else if (choice == 4)
        {
            int x;
            printf("Enter the value: ");
            scanf("%d", &x);
            insertEnd(x);
        }
        else if (choice == 5)
        {
            deleteBegin();
        }
        else if (choice == 6)
        {
            deleteEnd();
        }
        else if (choice == 7)
        {
            int pos;
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteElement(pos);
        }
        else if (choice == 8)
        {
            reverseLinkedList();
        }
        else if (choice == 9)
        {
            removeDuplicates();
        }
        else if (choice == 10)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice, Please try again.\n");
        }

        display();
    }

    return 0;
}
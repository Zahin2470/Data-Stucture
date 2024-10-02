#include <stdio.h>
#include <stdlib.h>
#define n 3
int q[n], f = -1, r = -1;

void enqueue(int item)
{
    if ((r + 1) % n == f)
    {
        printf("Queue Overflow");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        q[r] = item;
    }
    else
    {
        r = (r + 1) % n;
        q[r] = item;
    }
}

void dequeue()
{
    if (f == -1 && r == -1)
    {
        printf("Queue Empty");
    }
    else if (f == r)
    {
        printf("%d", q[f]);
        f = r = -1;
    }
    else
    {
        printf("%d", q[f]);
        f = (f + 1) % n;
    }
}

void printqueue()
{
    int i = f;
    if (f == -1 && r == -1)
    {
        printf("Empty\n");
    }
    else
    {
        while (1)
        {
            printf("%d ", q[i]);
            i = (i + 1) % n;
            if (i == (r + 1) % n)
            {
                break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printqueue();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
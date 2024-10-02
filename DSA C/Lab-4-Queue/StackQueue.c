#include <stdio.h>

#define size 100

int S[size];
int top = -1;

int q[size];
int f = -1, r = -1;

void push(int item)
{
    if (top + 1 == size)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        S[top] = item;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return S[top--];
    }
}

void enqueue(int item)
{
    if ((r + 1) % size == f)
    {
        printf("Queue Overflow\n");
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
    }
    else
    {
        r = (r + 1) % size;
    }
    q[r] = item;
}

void printQueue()
{
    int i = f;
    if (f == -1 && r == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue: ");
        while (1)
        {
            printf("%d ", q[i]);
            i = (i + 1) % size;
            if (i == (r + 1) % size)
            {
                break;
            }
        }
        printf("\n");
    }
}

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        push(i);
        enqueue(pop());
    }

    printQueue();

    return 0;
}
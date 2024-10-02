#include <stdio.h>
#include <stdlib.h>

#define n 5

int q[n], f = -1, r = -1;

void enqueue(int item)
{
    if ((r + 1) % n == f)
    {
        printf("Queue Overflow\n");
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
        printf("Queue Empty\n");
    }
    else if (f == r)
    {
        printf("%d\n", q[f]);
        f = r = -1;
    }
    else
    {
        printf("%d\n", q[f]);
        f = (f + 1) % n;
    }
}

void removeNegative() {
    while (f != -1 && f != (r + 1) % n) {
        if (q[f] >= 0) {
            enqueue(q[f]);
        }
        f = (f + 1) % n;
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(-3);
    enqueue(4);
    enqueue(-5);

    removeNegative();

    printf("Queue : ");
    for (int i = f; i != -1 && i != (r + 1) % n; i = (i + 1) % n)
    {
        printf("%d ", q[i]);
    }
    printf("\n");

    return 0;
}

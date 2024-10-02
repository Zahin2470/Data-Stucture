#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int stack[MAX_SIZE];
int top = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = x;
    }
}

int dequeue() {
    int item;
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return item;
    }
}

void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push.\n");
    } else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    int item;
    if (top == -1) {
        printf("Stack underflow. Cannot pop.\n");
        return -1;
    } else {
        item = stack[top];
        top--;
        return item;
    }
}

void reverseAndEnqueue(int k) {
    // Remove the first k elements from the front of the queue
    for (int i = 0; i < k; i++) {
        int item = dequeue();
        if (item != -1) {
            // Push the removed element onto the stack
            push(item);
        }
    }

    // Pop elements from the stack and enqueue them at the rear of the queue
    while (top != -1) {
        int item = pop();
        enqueue(item);
    }
}

void displayQueue() {
    int i = front;
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    int k = 3; // Number of elements to remove, reverse, and append
    printf("Original ");
    displayQueue();

    reverseAndEnqueue(k);

    printf("After removing %d elements, reversing, and appending ", k);
    displayQueue();

    return 0;
}

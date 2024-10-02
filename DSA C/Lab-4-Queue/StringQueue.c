#include <stdio.h>
#include <stdlib.h>

#define size 100

char q[size];
int f = -1, r = -1;

void enqueue(char item) {

    if ((r + 1) % size == f) {
        printf("Queue Overflow\n");
    } 
    else if (f == -1 && r == -1) {
            f = r = 0;
        } 
    else {
            r = (r + 1) % size;
        }
        q[r] = item;
    }

void compressedQueue(char str[]) {
    printf("Compressed String: ");
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            enqueue(str[i]);
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

int main() {
    char inputString[size];

    printf("Enter a string: ");

    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < size - 1) {
        inputString[i++] = ch;
    }
    inputString[i] = '\0';

    compressedQueue(inputString);

    return 0;
}
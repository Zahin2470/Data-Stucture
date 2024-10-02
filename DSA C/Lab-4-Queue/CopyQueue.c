#include <stdio.h>
#include <stdlib.h>

#define n 5

int q1[n], f1 = -1, r1 = -1;
int q2[n], f2 = -1, r2 = -1;

void enqueue1(int item) {
    if ((r1 + 1) % n == f1) {
        printf("Queue1 Overflow\n");
    } else if (f1 == -1 && r1 == -1) {
        f1 = r1 = 0;
        q1[r1] = item;
    } else {
        r1 = (r1 + 1) % n;
        q1[r1] = item;
    }
}

void enqueue2(int item) {
    if ((r2 + 1) % n == f2) {
        printf("Queue2 Overflow\n");
    } else if (f2 == -1 && r2 == -1) {
        f2 = r2 = 0;
        q2[r2] = item;
    } else {
        r2 = (r2 + 1) % n;
        q2[r2] = item;
    }
}

void copyQueue() {
    if(f1 == -1 && r1 == -1){
        printf("Queue1 is Epmty\n");
    }
    else{
        int i = f1;
        while(1){
            enqueue2(q1[i]);
            i = (i + 1) % n;
            if(i == (r1 + 1)){
                printf("Overflow");
            }
        }
    }

        printf("Queue2 copied from Queue1\n");
    }

void printQueue2() {
    int i = f2;
    if (f2 == -1 && r2 == -1) {
        printf("Queue2 is Empty\n");
    } else {
        while (1) {
            printf("%d ", q2[i]);
            i = (i + 1) % n;
            if (i == (r2 + 1) % n) {
                break;
            }
        }
        printf("\n");
    }
}

int main() {

    enqueue1(1);
    enqueue1(2);
    enqueue1(3);
    enqueue1(4);
    enqueue1(5);

    copyQueue();

    printf("Queue2: ");
    printQueue2();

    return 0;
}
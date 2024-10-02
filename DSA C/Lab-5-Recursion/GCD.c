#include <stdio.h>

int gcd(int a, int b) {
    if (b != 0) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}

int main()
{
    int num1, num2;

    printf("Input first number: ");
    scanf("%d", &num1);
    printf("Input second number: ");
    scanf("%d", &num2);

    printf("Output GCD : %d\n", gcd(num1, num2));

    return 0;
}
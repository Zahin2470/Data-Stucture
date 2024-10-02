#include <stdio.h>

int gcd(int a, int b) {
    if (b != 0) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;

    printf("Input first number: ");
    scanf("%d", &num1);
    printf("Input second number: ");
    scanf("%d", &num2);

    printf("Output LCM : %d\n", lcm(num1, num2));

    return 0;
}

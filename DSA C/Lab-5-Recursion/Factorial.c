#include <stdio.h>

int fact(int x)
{
    if (x == 1)
        return 1;
    else
        return x * fact(x - 1);
}

int main()
{
    int x, result;
    printf("Input Any Number : ");
    scanf("%d", &x);
    result = fact(x);
    printf("Factorial of x = %d", result);
}
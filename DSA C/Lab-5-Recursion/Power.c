#include <stdio.h>

int power(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, y - 1);
    }
}

int main()
{
    int x, y, result;

    printf("Input any number: ");
    scanf("%d", &x);

    printf("Input power: ");
    scanf("%d", &y);

    result = power(x,y);

    printf("Output : %d\n", result);

    return 0;
}
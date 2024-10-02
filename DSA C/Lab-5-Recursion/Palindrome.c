#include <stdio.h>

int palindrome(int num, int temp)
{
    int sum = 0;

    if (temp != 0){
        int reverse = temp % 10;
        sum = sum * 10 + reverse;
        palindrome(num, temp / 10);
    }
    else{
        if (num == sum){
            printf("%d is a palindrome.\n", num);
        }
        else{
            printf("%d is not a palindrome.\n", num);
        }
    }
    return 0;
}

int main()
{
    int num;

    printf("Enter a number : ");
    scanf("%d", &num);

    palindrome(num, num);
    return 0;
}

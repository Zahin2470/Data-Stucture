#include <stdio.h>
#include <string.h>

// Function to remove duplicates from a string using recursion
void removeDuplicates(char *str, int index, int length) {
    if (index >= length) {
        return;  // Base case: reached the end of the string
    }

    // Check if the current character is already present in the substring [0, index - 1]
    for (int i = 0; i < index; i++) {
        if (str[i] == str[index]) {
            // Shift the characters to the left to remove the duplicate
            for (int j = index; j < length - 1; j++) {
                str[j] = str[j + 1];
            }
            str[length - 1] = '\0';  // Null-terminate the string

            // After removing the duplicate, recursively check the rest of the string
            removeDuplicates(str, index, length - 1);
            return;
        }
    }

    // If no duplicate is found for the current character, check the next character
    removeDuplicates(str, index + 1, length);
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    // Call the removeDuplicates function
    removeDuplicates(str, 0, strlen(str));

    // Output the string after removing duplicates
    printf("String after removing duplicates: %s\n", str);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Function to delete duplicate values from an array
void DeleteDuplicate(int n, int *p) {
    if (n <= 1) {
        // No duplicates if array size is 1 or less
        return;
    }

    // Sort the array to bring duplicates together
    qsort(p, n, sizeof(int), compare);

    // Traverse the sorted array and remove duplicates
    int i, j;
    for (i = 0, j = 1; j < n; j++) {
        if (p[i] != p[j]) {
            i++;
            p[i] = p[j];
        }
    }

    // Adjust the size of the array
    n = i + 1;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int*)malloc(n * sizeof(int));

    // Input the elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to delete duplicate values
    DeleteDuplicate(n, arr);

    // Output the array after deleting duplicates
    printf("Array after deleting duplicates:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}

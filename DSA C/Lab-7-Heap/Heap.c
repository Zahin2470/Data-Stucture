#include <stdio.h>
#include <stdlib.h>

// Function to perform the insert operation in a min heap
void insert(int heap[], int n, int key) {
    // Add the new key at the end of the heap
    heap[n] = key;
    
    // Fix the violated heap property by traversing up
    int i = n;
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        // Swap the current node with its parent
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        // Move to the parent index
        i = (i - 1) / 2;
    }
}

// Function to perform the deletion operation in a min heap
void deleteRoot(int heap[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty.\n");
        return;
    }

    // Replace the root with the last element
    heap[0] = heap[*n - 1];
    (*n)--;

    // Fix the violated heap property by traversing down
    int i = 0;
    while (1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;

        // Find the smallest among the current node, left child, and right child
        if (leftChild < *n && heap[leftChild] < heap[smallest])
            smallest = leftChild;
        if (rightChild < *n && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        // If the smallest is the current node, heap property is restored
        if (smallest == i)
            break;

        // Swap the current node with the smallest child
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        // Move to the smallest child index
        i = smallest;
    }
}

// Function to find the smallest and largest elements in a heap
void findMinMax(int heap[], int n) {
    if (n <= 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Smallest Element: %d\n", heap[0]);
    
    int i = n - 1;
    // In a min heap, the largest element is at the last index
    printf("Largest Element: %d\n", heap[i]);
}

// Function to perform heap sort without using a separate heapify function
void heapSort(int arr[], int n) {
    // Build a min heap
    for (int i = 1; i < n; i++) {
        int j = i;
        // Fix the violated heap property by traversing up
        while (j > 0 && arr[j] < arr[(j - 1) / 2]) {
            // Swap the current node with its parent
            int temp = arr[j];
            arr[j] = arr[(j - 1) / 2];
            arr[(j - 1) / 2] = temp;

            // Move to the parent index
            j = (j - 1) / 2;
        }
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (minimum element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int j = 0;
        // Fix the violated heap property by traversing down
        while (1) {
            int leftChild = 2 * j + 1;
            int rightChild = 2 * j + 2;
            int smallest = j;

            // Find the smallest among the current node, left child, and right child
            if (leftChild < i && arr[leftChild] < arr[smallest])
                smallest = leftChild;
            if (rightChild < i && arr[rightChild] < arr[smallest])
                smallest = rightChild;

            // If the smallest is the current node, heap property is restored
            if (smallest == j)
                break;

            // Swap the current node with the smallest child
            temp = arr[j];
            arr[j] = arr[smallest];
            arr[smallest] = temp;

            // Move to the smallest child index
            j = smallest;
        }
    }
}

int main() {
    // Example usage
    int heap[100], n = 0;
    
    // Insert Operation
    insert(heap, n++, 3);
    insert(heap, n++, 2);
    insert(heap, n++, 15);
    insert(heap, n++, 5);
    insert(heap, n++, 4);
    insert(heap, n++, 45);

    printf("Min Heap after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    // Deletion Operation
    deleteRoot(heap, &n);
    printf("Min Heap after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    // Smallest and Largest Element
    findMinMax(heap, n);

    // Heap Sort
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, arr_size);

    printf("Sorted array using Heap Sort:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

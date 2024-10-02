#include <stdio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    // Assuming you have a binary search tree already created
    // You can use the search function like this:
    struct Node *root = NULL;
    struct Node *result = search(root, 40);

    if (result != NULL) {
        printf("Element found: %d\n", result->data);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

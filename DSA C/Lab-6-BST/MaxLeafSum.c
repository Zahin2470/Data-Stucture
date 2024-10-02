#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new binary tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to compute the sum of leaf nodes in a binary tree and find the maximum
int sumAndMaxLeafNodes(struct Node* root, int* maxSum) {
    if (root == NULL)
        return 0;

    // If it's a leaf node, return its value
    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }

    // Recur for left and right subtrees
    int leftSum = sumAndMaxLeafNodes(root->left, maxSum);
    int rightSum = sumAndMaxLeafNodes(root->right, maxSum);

    // If both left and right subtrees are NULL, it's a leaf node
    if (root->left != NULL && root->right != NULL) {
        // Update maxSum if the current leaf node's sum is greater
        int currentSum = leftSum + rightSum + root->data;
        if (currentSum > *maxSum) {
            *maxSum = currentSum;
        }
    }

    // Return the sum of left and right subtrees
    return leftSum + rightSum ;
}

// Function to compute the sum of leaf nodes in a binary tree and find the maximum
int sumAndMaxLeafNodesWrapper(struct Node* root) {
    int maxSum = 0;

    // Start the recursive process
    int totalSum = sumAndMaxLeafNodes(root, &maxSum);

    printf("Maximum sum of leaf nodes: %d\n", maxSum);

    return totalSum;
}

// Driver program to test the function
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    int totalSum = sumAndMaxLeafNodesWrapper(root);
    printf("Total sum of leaf nodes: %d\n", totalSum);

    return 0;
}
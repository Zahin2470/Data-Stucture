#include <stdio.h>
#include <limits.h>
#include<stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxPathSumUtil(struct TreeNode* root, int* maxSum) {
    if (root == NULL) {
        return 0;
    }

    // Recursively calculate the maximum path sum for the left and right subtrees
    int leftSum = maxPathSumUtil(root->left, maxSum);
    int rightSum = maxPathSumUtil(root->right, maxSum);

    // Calculate the maximum path sum for the current subtree rooted at 'root'
    int currentSum = root->val + max(0, leftSum) + max(0, rightSum);

    // Update the global maximum path sum if the current subtree has a higher sum
    *maxSum = max(*maxSum, currentSum);

    // Return the maximum path sum achievable from the current subtree rooted at 'root'
    return root->val + max(0, max(leftSum, rightSum));
}

int maxPathSum(struct TreeNode* root) {
    // Initialize the maximum path sum to the minimum possible value
    int maxSum = INT_MIN;

    // Call the utility function to recursively find the maximum path sum
    maxPathSumUtil(root, &maxSum);

    // Return the final maximum path sum
    return maxSum;
}

int main() {
    // Example usage:
    // Create a binary tree (you can customize this for your own tree)
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 10;
    root->left = malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->val = 10;
    root->left->left = malloc(sizeof(struct TreeNode));
    root->left->left->val = 15;
    root->left->right = malloc(sizeof(struct TreeNode));
    root->left->right->val = 1;
    root->right->right = malloc(sizeof(struct TreeNode));
    root->right->right->val = 5;
    root->right->right->left = malloc(sizeof(struct TreeNode));
    root->right->right->left->val = 3;
    root->right->right->right = malloc(sizeof(struct TreeNode));
    root->right->right->right->val = 4;

    // Call the function to find the maximum path sum
    int result = maxPathSum(root);

    // Print the result
    printf("Maximum Path Sum: %d\n", result);

    // Remember to free the allocated memory for the tree
    // (Not shown in this simplified example)
    
    return 0;
}
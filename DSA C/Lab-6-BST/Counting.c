#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into a BST
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the height of a BST
int height(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    }

    return 1 + std::max(height(root->left) ,height(root->right));

}

// Function to count the number of nodes in a BST
int nodeCount(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

// Function to count the number of leaf nodes in a BST
int leafCount(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return leafCount(root->left) + leafCount(root->right);
}

void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->val);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->val);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 23);
    insert(root, 14);
    insert(root, 44);
    insert(root, 12);
    insert(root, 18);
    insert(root, 52);
    insert(root, 30);
    insert(root, 45);
    insert(root, 18);
    insert(root, 10);
    insert(root, 20);
    insert(root, 55);

    printf("Height of the BST: %d\n", height(root));
    printf("Node count of the BST: %d\n", nodeCount(root));
    printf("Leaf count of the BST: %d\n", leafCount(root));

    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);

    printf("\nPre-order traversal of the BST: ");
    preOrderTraversal(root);

    printf("\nPost-order traversal of the BST: ");
    postOrderTraversal(root);

    return 0;
}
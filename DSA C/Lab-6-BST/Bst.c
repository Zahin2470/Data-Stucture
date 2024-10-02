#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Function to find the node with the minimum key in a BST
struct Node* findMin(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to find the successor of a given node in a BST
struct Node* findSuccessor(struct Node* root, struct Node* node) {
    if (node->right != NULL)
        return findMin(node->right);

    struct Node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }

    return successor;
}

// Function to find the node with the maximum key in a BST
struct Node* findMax(struct Node* node) {
    struct Node* current = node;

    while (current && current->right != NULL)
        current = current->right;

    return current;
}

// Function to find the predecessor of a given node in a BST
struct Node* findPredecessor(struct Node* root, struct Node* node) {
    if (node->left != NULL)
        return findMax(node->left);

    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else
            break;
    }

    return predecessor;
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Driver program
int main() {
    struct Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
        root = insert(root, keys[i]);

    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    struct Node* successorNode = findSuccessor(root, root->right);
    printf("Successor of %d is %d\n", root->right->data, successorNode ? successorNode->data : -1);

    struct Node* predecessorNode = findPredecessor(root, root->left);
    printf("Predecessor of %d is %d\n", root->left->data, predecessorNode ? predecessorNode->data : -1);

    return 0;
}

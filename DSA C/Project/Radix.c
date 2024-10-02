#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie node structure
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
};

// Function to create a new TrieNode
struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (node) {
        node->isEndOfWord = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

// Function to insert a word into the Trie
void insertWord(struct TrieNode* root, const char* word) {
    struct TrieNode* current = root;
    int len = strlen(word);

    for (int level = 0; level < len; level++) {
        int index = word[level] - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }

    current->isEndOfWord = 1;
}

// Function to search for a word in the Trie
int searchWord(struct TrieNode* root, const char* word) {
    struct TrieNode* current = root;
    int len = strlen(word);

    for (int level = 0; level < len; level++) {
        int index = word[level] - 'a';
        if (!current->children[index]) {
            return 0; // Word not found
        }
        current = current->children[index];
    }

    return (current != NULL && current->isEndOfWord);
}

// Function to check if a node has any children
int hasChildren(struct TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            return 1;
        }
    }
    return 0;
}

// Function to delete a word from the Trie
int deleteWord(struct TrieNode* root, const char* word, int level, int len) {
    if (root == NULL) {
        return 0;
    }

    if (level == len) {
        if (root->isEndOfWord) {
            root->isEndOfWord = 0;

            // If the current node has no other children, it can be deleted
            return !hasChildren(root);
        }
    } else {
        int index = word[level] - 'a';
        if (deleteWord(root->children[index], word, level + 1, len)) {
            free(root->children[index]);

            // Recursively delete the nodes that are not needed
            return !hasChildren(root) && !root->isEndOfWord;
        }
    }

    return 0;
}

// Function to display the Trie
void displayTrie(struct TrieNode* root, char* buffer, int depth) {
    if (root->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            buffer[depth] = 'a' + i;
            displayTrie(root->children[i], buffer, depth + 1);
        }
    }
}

// Function to suggest autocomplete words
void autocompleteSuggestion(struct TrieNode* root, const char* prefix) {
    struct TrieNode* current = root;
    int len = strlen(prefix);

    for (int level = 0; level < len; level++) {
        int index = prefix[level] - 'a';
        if (!current->children[index]) {
            printf("No suggestions found for %s\n", prefix);
            return;
        }
        current = current->children[index];
    }

    char buffer[100];
    strcpy(buffer, prefix);
    displayTrie(current, buffer, len);
}

// Function to free the memory allocated for the Trie
void freeTrie(struct TrieNode* root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(root->children[i]);
    }

    free(root);
}

int main() {
    struct TrieNode* root = createNode();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a word\n");
        printf("2. Delete a word\n");
        printf("3. Display the tree\n");
        printf("4. Autocomplete suggestion\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char word[100];
                printf("Enter the word to insert: ");
                scanf("%s", word);
                insertWord(root, word);
                printf("Word inserted successfully.\n");
                break;
            }
            case 2: {
                char word[100];
                printf("Enter the word to delete: ");
                scanf("%s", word);
                if (deleteWord(root, word, 0, strlen(word))) {
                    printf("Word deleted successfully.\n");
                } else {
                    printf("Word not found.\n");
                }
                break;
            }
            case 3: {
                char buffer[100];
                displayTrie(root, buffer, 0);
                break;
            }
            case 4: {
                char prefix[100];
                printf("Enter the prefix for autocomplete: ");
                scanf("%s", prefix);
                autocompleteSuggestion(root, prefix);
                break;
            }
            case 5: {
                freeTrie(root);
                printf("Exiting the program.\n");
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
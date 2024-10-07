#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new binary tree node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count the number of nodes in a subtree
int countNodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);  // Count root + left + right
}

// Function to return the number of nodes in the left subtree of the given node
int countLeftSubtreeNodes(Node *node) {
    if (node == NULL || node->left == NULL) {
        return 0; // No left subtree
    }
    return countNodes(node->left);  // Count nodes in the left subtree
}

// Example usage
int main() {
    // Create a sample tree
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Test the function to count nodes in the left subtree of the root node
    printf("Number of nodes in the left subtree of node 1: %d\n", countLeftSubtreeNodes(root));      // Output should be 3 (2, 4, 5)
    printf("Number of nodes in the left subtree of node 2: %d\n", countLeftSubtreeNodes(root->left)); // Output should be 1 (4)
    printf("Number of nodes in the left subtree of node 3: %d\n", countLeftSubtreeNodes(root->right)); // Output should be 1 (6)

    return 0;
}

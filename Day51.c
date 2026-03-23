#include <stdio.h>
#include <stdlib.h>

// Structure of BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        // If both smaller → go left
        if (p < root->data && q < root->data)
            root = root->left;

        // If both greater → go right
        else if (p > root->data && q > root->data)
            root = root->right;

        // Split point → LCA
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, x, p, q;
    struct Node* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input BST elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Input nodes p and q
    scanf("%d %d", &p, &q);

    // Find LCA
    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}
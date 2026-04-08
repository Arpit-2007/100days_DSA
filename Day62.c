#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add edge
void addEdge(struct Node* adj[], int u, int v, int type) {
    // Add v to u's list
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    // If undirected, add u to v's list
    if (type == 0) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }
}

// Function to print graph
void printGraph(struct Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Create adjacency list
    struct Node* adj[n];

    // Initialize all lists as NULL
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    int type;
    printf("Enter 0 for Undirected, 1 for Directed: ");
    scanf("%d", &type);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, type);
    }

    printf("\nAdjacency List:\n");
    printGraph(adj, n);

    return 0;
}
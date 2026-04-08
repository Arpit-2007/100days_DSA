#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Add edge (directed)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void dfs(int node, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    // Push to stack after visiting all neighbors
    stack[++(*top)] = node;
}

// Topological sort
void topoSort(int n, struct Node* adj[]) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int stack[n];
    int top = -1;

    // DFS for all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &top);
        }
    }

    // Print topological order (reverse of stack)
    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];

    // Initialize
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    topoSort(n, adj);

    return 0;
}
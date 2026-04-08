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
int dfs(int node, struct Node* adj[], int visited[], int recStack[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
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

    int visited[n], recStack[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int hasCycle = 0;

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
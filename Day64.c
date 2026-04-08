#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// BFS function
void bfs(int start, struct Node* adj[], int n) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int queue[n];
    int front = 0, rear = 0;

    // Start from source
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
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

    int s;
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    bfs(s, adj, n);

    return 0;
}
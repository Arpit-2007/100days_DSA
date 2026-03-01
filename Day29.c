#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to rotate list right by k
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    // Find length and last node
    struct Node* temp = head;
    int n = 1;

    while (temp->next) {
        temp = temp->next;
        n++;
    }

    k = k % n;
    if (k == 0)
        return head;

    // Make circular
    temp->next = head;

    // Move to (n-k)th node
    int steps = n - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // New head
    struct Node* newHead = newTail->next;

    // Break circle
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, x;
    struct Node *head = NULL, *tail = NULL, *newNode;

    // Input
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
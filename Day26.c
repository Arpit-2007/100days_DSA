#include <stdio.h>
#include <stdlib.h>

/* Doubly linked list node */
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

/* Function to create a new node */
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/* Insert node at the end */
struct Node* insertAtEnd(struct Node* head, int val) {
    struct Node* newNode = createNode(val);

    /* If list is empty */
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;

    /* Traverse to last node */
    while (temp->next != NULL) {
        temp = temp->next;
    }

    /* Link the new node */
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

/* Traverse forward and print */
void traverseForward(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
}

int main() {
    int n, val;
    struct Node* head = NULL;

    /* Input number of nodes */
    scanf("%d", &n);

    /* Input elements and insert sequentially */
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertAtEnd(head, val);
    }

    /* Output forward traversal */
    traverseForward(head);

    return 0;
}
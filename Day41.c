#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {   // Queue is empty
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
int dequeue() {
    if (front == NULL) {   // Queue is empty
        return -1;
    }

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;

    if (front == NULL)   // If queue becomes empty
        rear = NULL;

    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    char operation[20];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(value);
        }
        else if (strcmp(operation, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}
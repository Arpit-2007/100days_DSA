#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

/* Check if empty */
int empty() {
    return (front == -1);
}

/* Check if full */
int isFull() {
    return ((rear + 1) % MAX == front);
}

/* Return size */
int size() {
    if (empty())
        return 0;
    if (rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

/* push_back */
void push_back(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (empty())
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;
    deque[rear] = value;
}

/* push_front */
void push_front(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (empty())
        front = rear = 0;
    else
        front = (front - 1 + MAX) % MAX;
    deque[front] = value;
}

/* pop_front */
void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

/* pop_back */
void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + MAX) % MAX;
}

/* front element */
int get_front() {
    if (empty()) return -1;
    return deque[front];
}

/* back element */
int get_back() {
    if (empty()) return -1;
    return deque[rear];
}

/* clear deque */
void clear() {
    front = rear = -1;
}

/* reverse deque */
void reverse() {
    if (empty()) return;

    int n = size();
    int i = 0, j = n - 1;

    while (i < j) {
        int idx1 = (front + i) % MAX;
        int idx2 = (front + j) % MAX;

        int temp = deque[idx1];
        deque[idx1] = deque[idx2];
        deque[idx2] = temp;

        i++;
        j--;
    }
}

/* sort deque (simple bubble sort) */
void sort() {
    int n = size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int idx1 = (front + j) % MAX;
            int idx2 = (front + j + 1) % MAX;

            if (deque[idx1] > deque[idx2]) {
                int temp = deque[idx1];
                deque[idx1] = deque[idx2];
                deque[idx2] = temp;
            }
        }
    }
}

/* display deque */
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
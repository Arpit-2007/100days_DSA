#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

/* Insert element in sorted order */
void insert(int x) {
    if (size == MAX) {
        return;
    }

    int i = size - 1;

    // Shift larger elements right
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

/* Delete highest priority (smallest element) */
int delete() {
    if (size == 0)
        return -1;

    int value = pq[0];

    // Shift elements left
    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
    return value;
}

/* Peek highest priority */
int peek() {
    if (size == 0)
        return -1;

    return pq[0];
}

int main() {
    int N;
    char operation[10];
    int value;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        }
        else if (strcmp(operation, "delete") == 0) {
            printf("%d\n", delete());
        }
        else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
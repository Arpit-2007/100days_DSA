#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

/* Swap function */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify Up (for insert) */
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

/* Heapify Down (for extractMin) */
void heapifyDown(int index) {
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = left;

        if (right < size && heap[right] < heap[left])
            smallest = right;

        if (heap[index] > heap[smallest]) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

/* Insert operation */
void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

/* Peek operation */
int peek() {
    if (size == 0)
        return -1;
    return heap[0];
}

/* Extract Min operation */
int extractMin() {
    if (size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return min;
}

/* Main function */
int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char operation[20];
        scanf("%s", operation);

        if (operation[0] == 'i') {  // insert
            int value;
            scanf("%d", &value);
            insert(value);
        }
        else if (operation[0] == 'p') {  // peek
            int result = peek();
            printf("%d\n", result);
        }
        else if (operation[0] == 'e') {  // extractMin
            int result = extractMin();
            printf("%d\n", result);
        }
    }

    return 0;
}
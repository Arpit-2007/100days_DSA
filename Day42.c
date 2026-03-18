#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

// Create stack
Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int) * capacity);
    return s;
}

// Push to stack
void push(Stack* s, int x) {
    s->arr[++s->top] = x;
}

// Pop from stack
int pop(Stack* s) {
    return s->arr[s->top--];
}

// Check empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

int main() {
    int N;
    scanf("%d", &N);

    int *queue = (int*)malloc(sizeof(int) * N);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &queue[i]);
    }

    // Create stack
    Stack* stack = createStack(N);

    // Step 1: Push all queue elements into stack
    for (int i = 0; i < N; i++) {
        push(stack, queue[i]);
    }

    // Step 2: Pop from stack back into queue
    int index = 0;
    while (!isEmpty(stack)) {
        queue[index++] = pop(stack);
    }

    // Print reversed queue
    for (int i = 0; i < N; i++) {
        printf("%d ", queue[i]);
    }

    free(queue);
    free(stack->arr);
    free(stack);

    return 0;
}
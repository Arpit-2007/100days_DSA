#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

void pop() {
    if (top != -1) {
        top--;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // number of pops
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    // display stack from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) printf(" ");
    }

    return 0;
}
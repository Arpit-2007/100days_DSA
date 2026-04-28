#include <stdio.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table is full, cannot insert %d\n", key);
}

int search(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == key)
            return index;

        if (table[index] == EMPTY)
            return -1;

        i++;
    }
    return -1;
}

int main() {
    int m, q;

    // Input size of hash table
    scanf("%d", &m);

    int table[m];

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    // Number of operations
    scanf("%d", &q);

    char op[10];
    int key;

    while (q--) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(table, m, key);
        } else if (op[0] == 'S') {
            int result = search(table, m, key);
            if (result == -1)
                printf("NOT FOUND\n");
            else
                printf("FOUND\n");
        }
    }

    return 0;
}
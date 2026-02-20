#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// simple hash map using arrays (for exam use)
typedef struct {
    long long key;
    int count;
} Hash;

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // hash table (simple, large enough)
    Hash hash[MAX];
    int size = 0;

    long long prefixSum = 0;
    int result = 0;

    // prefix sum 0 occurs once initially
    hash[size++] = (Hash){0, 1};

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // search in hash
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (hash[j].key == prefixSum) {
                result += hash[j].count;
                hash[j].count++;
                found = 1;
                break;
            }
        }

        // if not found, insert
        if (!found) {
            hash[size++] = (Hash){prefixSum, 1};
        }
    }

    printf("%d\n", result);
    return 0;
}
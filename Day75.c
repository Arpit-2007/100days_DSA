#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // Hashing using arrays (for simplicity)
    int hash[2 * MAX] = {0};   // stores index+1
    int offset = MAX;          // to handle negative sums

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0 from beginning
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Case 2: seen before
        if (hash[prefixSum + offset] != 0) {
            int prevIndex = hash[prefixSum + offset] - 1;
            int len = i - prevIndex;
            if (len > maxLen)
                maxLen = len;
        } else {
            // store first occurrence
            hash[prefixSum + offset] = i + 1;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = 1000000000;  // large value
    int bestL = arr[left], bestR = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        // Update closest pair
        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            bestL = arr[left];
            bestR = arr[right];
        }

        // Move pointers
        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", bestL, bestR);
    return 0;
}

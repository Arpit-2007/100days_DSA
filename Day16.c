#include <stdio.h>

int main() {
    int n;

    // Input size of array
    scanf("%d", &n);

    int arr[n];
    int visited[n];  // to mark counted elements

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;  // initialize visited array
    }

    // Count frequency
    for (int i = 0; i < n; i++) {

        // Skip already counted elements
        if (visited[i] == 1)
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;  // mark as counted
            }
        }

        // Print result
        printf("%d:%d ", arr[i], count);
    }

    return 0;
}

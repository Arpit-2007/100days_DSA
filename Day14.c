#include <stdio.h>

int main() {
    int n, i, j;
    
    // Read size of matrix
    scanf("%d", &n);

    int matrix[n][n];
    int isIdentity = 1;  // assume true

    // Read matrix elements
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity matrix condition
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j && matrix[i][j] != 1) {
                isIdentity = 0;
                break;
            }
            if (i != j && matrix[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
        if (!isIdentity)
            break;
    }

    // Print result
    if (isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}

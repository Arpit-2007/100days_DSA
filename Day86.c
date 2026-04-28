#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long left = 0, right = n;
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        // Avoid overflow using division
        if (mid <= n / mid) {
            ans = mid;          // valid answer
            left = mid + 1;     // try bigger
        } else {
            right = mid - 1;    // too large
        }
    }

    printf("%lld\n", ans);

    return 0;
}
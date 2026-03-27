#include <stdio.h>

#define MAX 1000

int main() {
    int n, i;
    
    // Input size
    scanf("%d", &n);
    
    int arr[n];
    
    // Input array
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // Simple hash array (range assumption)
    int freq[2 * MAX + 1] = {0};  
    int offset = MAX; // to handle negative sums

    // Initialize
    freq[offset] = 1; // prefix sum = 0

    for(i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If this prefix sum seen before → add its frequency
        count += freq[prefixSum + offset];

        // Increase frequency
        freq[prefixSum + offset]++;
    }

    // Output result
    printf("%d", count);

    return 0;
}
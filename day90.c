#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (currentSum + arr[i] <= maxTime) {
            currentSum += arr[i];
        } else {
            painters++;
            currentSum = arr[i];
        }

        if (painters > k)
            return 0;
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int left = maxVal;
    int right = sum;
    int ans = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;        
            right = mid - 1;  
        } else {
            left = mid + 1;  
        }
    }

    printf("%d\n", ans);
    return 0;
}
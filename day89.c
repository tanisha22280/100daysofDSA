#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];
        }

        if (students > m)
            return 0;
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

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

        if (isPossible(arr, n, m, mid)) {
            ans = mid;        
            right = mid - 1;  
        } else {
            left = mid + 1;   
        }
    }

    printf("%d\n", ans);
    return 0;
}
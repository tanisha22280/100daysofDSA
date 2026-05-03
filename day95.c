#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float **buckets = (float **)malloc(n * sizeof(float *));
    int *sizes = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        int idx = (int)(n * arr[i]); 
        buckets[idx][sizes[idx]++] = arr[i];
    }

   for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], sizes[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(sizes);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }

    return 0;
}
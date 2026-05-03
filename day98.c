#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmp);

    Interval result[n];
    int index = 0;

    result[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index].end) {
            // Merge
            if (arr[i].end > result[index].end) {
                result[index].end = arr[i].end;
            }
        } else {
            index++;
            result[index] = arr[i];
        }
    }

    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}
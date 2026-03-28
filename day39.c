#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP 1000

typedef struct {
    int arr[MAX_HEAP];
    int size;
} MinHeap;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[parent] <= heap->arr[index]) break;
        swap(&heap->arr[parent], &heap->arr[index]);
        index = parent;
    }
}

void heapifyDown(MinHeap* heap, int index) {
    while (2 * index + 1 < heap->size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = left;
        if (right < heap->size && heap->arr[right] < heap->arr[left]) {
            smallest = right;
        }
        if (heap->arr[index] <= heap->arr[smallest]) break;
        swap(&heap->arr[index], &heap->arr[smallest]);
        index = smallest;
    }
}

void insert(MinHeap* heap, int val) {
    if (heap->size >= MAX_HEAP) return; // prevent overflow
    heap->arr[heap->size] = val;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int extractMin(MinHeap* heap) {
    if (heap->size == 0) return -1;
    int minVal = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return minVal;
}

int peek(MinHeap* heap) {
    if (heap->size == 0) return -1;
    return heap->arr[0];
}

int main() {
    int N;
    scanf("%d", &N);

    MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(&heap, x);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin(&heap));
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek(&heap));
        }
    }

    return 0;
}
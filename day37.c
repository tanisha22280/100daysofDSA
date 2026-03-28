#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int arr[MAX_SIZE];
    int size;
} PriorityQueue;

void insert(PriorityQueue* pq, int x) {
    if (pq->size >= MAX_SIZE) return; // prevent overflow
    pq->arr[pq->size++] = x;
}

int delete(PriorityQueue* pq) {
    if (pq->size == 0) return -1; // empty queue

    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i] < pq->arr[minIndex]) {
            minIndex = i;
        }
    }

    int minValue = pq->arr[minIndex];

    // Shift elements to fill the gap
    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }

    pq->size--;
    return minValue;
}

int peek(PriorityQueue* pq) {
    if (pq->size == 0) return -1;

    int minValue = pq->arr[0];
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i] < minValue) {
            minValue = pq->arr[i];
        }
    }
    return minValue;
}

int main() {
    int N;
    scanf("%d", &N);

    PriorityQueue pq;
    pq.size = 0;

    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            int x;
            scanf("%d", &x);
            insert(&pq, x);
        } else if (op[0] == 'd') { // delete
            int val = delete(&pq);
            printf("%d\n", val);
        } else if (op[0] == 'p') { // peek
            int val = peek(&pq);
            printf("%d\n", val);
        }
    }

    return 0;
}
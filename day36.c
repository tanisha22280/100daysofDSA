#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(CircularQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (!q->front) {
        // Queue empty
        q->front = q->rear = newNode;
        newNode->next = newNode; // circular link
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

void dequeue(CircularQueue* q) {
    if (!q->front) return; // empty queue

    Node* temp = q->front;
    if (q->front == q->rear) {
        // Only one element
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }
    free(temp);
    q->size--;
}

void printQueue(CircularQueue* q) {
    if (!q->front) return;

    Node* temp = q->front;
    for (int i = 0; i < q->size; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeQueue(CircularQueue* q) {
    while (q->size > 0) {
        dequeue(q);
    }
    free(q);
}

int main() {
    int n, m;
    scanf("%d", &n);

    CircularQueue* q = createQueue();
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    printQueue(q);
    freeQueue(q);
    return 0;
}
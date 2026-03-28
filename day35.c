#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (q->rear == NULL) { // empty queue
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        exit(1);
    }
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void displayQueue(Queue* q) {
    Node* curr = q->front;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) printf(" ");
        curr = curr->next;
    }
    printf("\n");
}

void freeQueue(Queue* q) {
    while (q->front != NULL) {
        dequeue(q);
    }
    free(q);
}

int main() {
    int n, val;
    scanf("%d", &n);

    Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    displayQueue(q);

    freeQueue(q);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

void push_front(Deque* dq, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->prev = NULL;
    node->next = dq->front;
    if (dq->front) dq->front->prev = node;
    dq->front = node;
    if (!dq->rear) dq->rear = node;
    dq->size++;
}

void push_back(Deque* dq, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    node->prev = dq->rear;
    if (dq->rear) dq->rear->next = node;
    dq->rear = node;
    if (!dq->front) dq->front = node;
    dq->size++;
}

int pop_front(Deque* dq) {
    if (!dq->front) return -1;
    Node* temp = dq->front;
    int val = temp->data;
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
    dq->size--;
    return val;
}

int pop_back(Deque* dq) {
    if (!dq->rear) return -1;
    Node* temp = dq->rear;
    int val = temp->data;
    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
    dq->size--;
    return val;
}

int front(Deque* dq) {
    if (!dq->front) return -1;
    return dq->front->data;
}

int back(Deque* dq) {
    if (!dq->rear) return -1;
    return dq->rear->data;
}

bool empty(Deque* dq) {
    return dq->size == 0;
}

int size(Deque* dq) {
    return dq->size;
}

void clear(Deque* dq) {
    Node* temp = dq->front;
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

void reverse(Deque* dq) {
    Node* temp = dq->front;
    Node* prev = NULL;
    dq->rear = dq->front;
    while (temp) {
        Node* next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }
    dq->front = prev;
}

void sort(Deque* dq) {
    if (!dq->front || !dq->front->next) return;
    bool swapped;
    do {
        swapped = false;
        Node* curr = dq->front;
        while (curr->next) {
            if (curr->data > curr->next->data) {
                int t = curr->data;
                curr->data = curr->next->data;
                curr->next->data = t;
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
}

void printDeque(Deque* dq) {
    Node* temp = dq->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeDeque(Deque* dq) {
    clear(dq);
    free(dq);
}

int main() {
    Deque* dq = createDeque();
    push_back(dq, 10);
    push_front(dq, 20);
    push_back(dq, 5);
    printf("Deque: "); printDeque(dq);  // 20 10 5
    printf("Front: %d\n", front(dq));  // 20
    printf("Back: %d\n", back(dq));    // 5
    pop_front(dq);
    pop_back(dq);
    printf("Deque after pop: "); printDeque(dq); // 10
    push_front(dq, 15);
    push_back(dq, 25);
    reverse(dq);
    printf("Reversed deque: "); printDeque(dq); // 25 10 15
    sort(dq);
    printf("Sorted deque: "); printDeque(dq);   // 10 15 25
    freeDeque(dq);
    return 0;
}
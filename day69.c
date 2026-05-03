#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* adj[MAX];

struct HeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u, w);
    node->next = adj[v];
    adj[v] = node;
}

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MinHeap* h, int i) {
    while (i > 0 && h->heap[i].dist < h->heap[(i - 1) / 2].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(struct MinHeap* h, int v, int dist) {
    h->heap[h->size].vertex = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

void dijkstra(int V, int src) {
    int dist[MAX];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (!isEmpty(&h)) {
        struct HeapNode top = pop(&h);
        int u = top.vertex;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int V = 5;

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(1, 4, 2);
    addEdge(2, 3, 4);
    addEdge(3, 0, 7);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);

    int src = 0;
    dijkstra(V, src);

    return 0;
}
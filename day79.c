#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

struct HeapNode {
    int vertex, dist;
};

struct MinHeap {
    int size;
    struct HeapNode arr[MAX];
};

struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}

void addEdge(int u, int v, int w) {
    struct Node* temp = newNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u, w);
    temp->next = adj[v];
    adj[v] = temp;
}

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(struct MinHeap* h, int i) {
    while (i > 0 && h->arr[i].dist < h->arr[(i - 1)/2].dist) {
        swap(&h->arr[i], &h->arr[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void heapifyDown(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(struct MinHeap* h, int v, int d) {
    h->arr[h->size].vertex = v;
    h->arr[h->size].dist = d;
    heapifyUp(h, h->size);
    h->size++;
}

struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

void dijkstra(int n, int src) {
    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (!isEmpty(&h)) {
        struct HeapNode top = pop(&h);
        int u = top.vertex;

        struct Node* temp = adj[u];

        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}
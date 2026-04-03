#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

void addEdge(struct Node* adj[], int u, int v) {
    // Add v to u's list
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = v;
    node->next = adj[u];
    adj[u] = node;

    node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = u;
    node->next = adj[v];
    adj[v] = node;
}

void printGraph(struct Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printGraph(adj, n);

    return 0;
}
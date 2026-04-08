#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int V;
int adj[MAX][MAX];
bool visited[MAX];
int stack[MAX], top = -1;

void push(int node) {
    stack[++top] = node;
}

void dfs(int node) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    push(node);
}

void topoSort() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; 
    }

    topoSort();

    return 0;
}
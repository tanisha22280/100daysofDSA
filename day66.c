#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int V; 
int adj[MAX][MAX]; 

bool visited[MAX];
bool recStack[MAX];

bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i))
                    return true;
            }
            else if (recStack[i]) {
                return true; 
            }
        }
    }

    recStack[node] = false; 
    return false;
}

bool hasCycle() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }

    return false;
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

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
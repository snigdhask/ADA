#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5
#define INFINITY 999999

int findMinKeyVertex(int V, int key[], bool mstSet[]) {
    int minKey = INFINITY;
    int minKeyVertex = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minKeyVertex = v;
        }
    }

    return minKeyVertex;
}

void printMST(int V, int parent[], int adjacencyMatrix[][MAX_VERTICES]) {
    printf("Minimum Spanning Tree:\n");
    int sum=0;
    for (int i = 1; i < V; i++) {
    sum+=adjacencyMatrix[i][parent[i]];
        printf("(%d - %d) Weight: %d\n", parent[i], i, adjacencyMatrix[i][parent[i]]);
    }
    printf("MST of the graph is %d ",sum);
}

void primMST(int V, int adjacencyMatrix[][MAX_VERTICES]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INFINITY;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKeyVertex(V, key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (adjacencyMatrix[u][v] && !mstSet[v] && adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjacencyMatrix[u][v];
            }
        }
    }

    printMST(V, parent, adjacencyMatrix);
}

int main() {
    int V = MAX_VERTICES;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(V, adjacencyMatrix);

    return 0;
}
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5
#define INFINITY 999999

int findMinKeyVertex(int V, int key[], bool mstSet[]) {
    int minKey = INFINITY;
    int minKeyVertex = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minKeyVertex = v;
        }
    }

    return minKeyVertex;
}

void printMST(int V, int parent[], int adjacencyMatrix[][MAX_VERTICES]) {
    printf("Minimum Spanning Tree:\n");
    int sum=0;
    for (int i = 1; i < V; i++) {
    sum+=adjacencyMatrix[i][parent[i]];
        printf("(%d - %d) Weight: %d\n", parent[i], i, adjacencyMatrix[i][parent[i]]);
    }
    printf("MST of the graph is %d ",sum);
}

void primMST(int V, int adjacencyMatrix[][MAX_VERTICES]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INFINITY;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKeyVertex(V, key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (adjacencyMatrix[u][v] && !mstSet[v] && adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjacencyMatrix[u][v];
            }
        }
    }

    printMST(V, parent, adjacencyMatrix);
}

int main() {
    int V = MAX_VERTICES;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(V, adjacencyMatrix);

    return 0;
}

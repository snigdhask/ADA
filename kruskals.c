#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to find the parent of a node in the disjoint set
int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform a union operation in the disjoint set
void unionSets(int parent[], int x, int y) {
    int xParent = findParent(parent, x);
    int yParent = findParent(parent, y);
    parent[yParent] = xParent;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(int V, int adjacencyMatrix[][MAX_VERTICES]) {
    int E = 0; // Count of edges
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                E++;
            }
        }
    }

    int edges[E][3]; // Array to store edges (src, dest, weight)
    int edgeIndex = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                edges[edgeIndex][0] = i;
                edges[edgeIndex][1] = j;
                edges[edgeIndex][2] = adjacencyMatrix[i][j];
                edgeIndex++;
            }
        }
    }

    // Step 1: Sort the edges in ascending order of their weights (using bubble sort for simplicity)
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp[3];
                temp[0] = edges[j][0];
                temp[1] = edges[j][1];
                temp[2] = edges[j][2];

                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];

                edges[j + 1][0] = temp[0];
                edges[j + 1][1] = temp[1];
                edges[j + 1][2] = temp[2];
            }
        }
    }

    int parent[V]; // Array to store parent of each vertex in disjoint set
    for (int v = 0; v < V; v++)
        parent[v] = v; // Initialize each node as its own parent

    // Step 2: Process each edge in sorted order
    int result[V - 1][2]; // Array to store the resulting minimum spanning tree
    int resultIndex = 0;

    for (int i = 0; i < E && resultIndex < V - 1; i++) {
        int x = findParent(parent, edges[i][0]);
        int y = findParent(parent, edges[i][1]);

        // If including this edge doesn't create a cycle, add it to the result
        if (x != y) {
            result[resultIndex][0] = edges[i][0];
            result[resultIndex][1] = edges[i][1];
            resultIndex++;

            unionSets(parent, x, y);
        }
    }

    // Print the MST
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < V - 1; i++) {
        printf("(%d - %d) Weight: %d\n", result[i][0], result[i][1], adjacencyMatrix[result[i][0]][result[i][1]]);
    }
}

int main() {
    int V;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]={
0,28,99,99,99,10,99,
    28,0,16,99,99,99,14,
    99,16,0,12,99,99,99,
    99,99,12,0,22,99,18,
    99,99,99,22,0,25,24,
    10,99,99,99,25,0,99,
    99,14,99,18,24,99,0};
    kruskalMST(V, adjacencyMatrix);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void DFS(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex, int visited[]) {
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(adjMatrix, vertices, i, visited);
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        adjMatrix[vertex1][vertex2] = 1;
        adjMatrix[vertex2][vertex1] = 1;
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    int visited[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal starting from vertex %d:\n", startVertex);
    DFS(adjMatrix, vertices, startVertex, visited);

    printf("\n");

    return 0;
}


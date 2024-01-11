#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int minDistance(int dist[], int visited[], int vertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("-> %d ", j);
}

void printSolution(int dist[], int parent[], int src, int vertices) {
    printf("Vertex\tDistance\tPath\n");

    for (int i = 0; i < vertices; i++) {
        printf("%d -> %d\t%d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int vertices) {
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);

        visited[u] = 1;

        for (int v = 0; v < vertices; v++) {
           
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src, vertices);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0; 
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges and weights (vertex1 vertex2 weight):\n");
    for (int i = 0; i < edges; i++) {
        int vertex1, vertex2, weight;
        scanf("%d %d %d", &vertex1, &vertex2, &weight);
        graph[vertex1][vertex2] = weight;
        graph[vertex2][vertex1] = weight; 
    }

    int src;
    printf("Enter the source vertex for Dijkstra's algorithm: ");
    scanf("%d", &src);

    dijkstra(graph, src, vertices);

    return 0;
}


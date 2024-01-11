#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void kruskalMST(struct Edge edges[], int vertices, int edgesCount) {
    struct Edge resultMST[vertices];
    int resultIndex = 0; 
    int i = 0; 

    struct Subset *subsets = (struct Subset *)malloc(vertices * sizeof(struct Subset));

    for (int v = 0; v < vertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    qsort(edges, edgesCount, sizeof(edges[0]), compareEdges);

    while (resultIndex < vertices - 1 && i < edgesCount) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            resultMST[resultIndex++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges of the Minimum Spanning Tree:\n");
    for (i = 0; i < resultIndex; i++) {
        printf("%d - %d : %d\n", resultMST[i].src, resultMST[i].dest, resultMST[i].weight);
    }

    free(subsets);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int edgesCount = (vertices * (vertices - 1)) / 2; 
    struct Edge *edgesList = (struct Edge *)malloc(edgesCount * sizeof(struct Edge));

    printf("Enter the edges and weights (vertex1 vertex2 weight):\n");
    int k = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            edgesList[k].src = i;
            edgesList[k].dest = j;
            printf("Enter the weight for edge %d - %d: ", i, j);
            scanf("%d", &edgesList[k].weight);
            k++;
        }
    }

    kruskalMST(edgesList, vertices, edgesCount);

    free(edgesList);

    return 0;
}


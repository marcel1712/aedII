#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjacencyList = (Node**) malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Add an edge to the graph (directed)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // For undirected graphs, uncomment below:
    // newNode = createNode(src);
    // newNode->next = graph->adjacencyList[dest];
    // graph->adjacencyList[dest] = newNode;
}

// Print the adjacency list representation of the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Free the memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjacencyList);
    free(graph);
}

int main() {
    int n, x, y;

    printf("Number of vertices: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    Graph* graph = createGraph(n);

    printf("Enter the pairs of vertices that form the edges.\n");
    printf("Enter -1 -1 to stop.\n");

    while (1) {
        printf("Edge (src dest): ");
        scanf("%d %d", &x, &y);

        if (x == -1 && y == -1) {
            break;
        }

        if (x < 0 || x >= n || y < 0 || y >= n) {
            printf("Invalid vertices! Enter numbers between 0 and %d.\n", n - 1);
            continue;
        }

        addEdge(graph, x, y);
    }

    printf("\nAdjacency List of the Graph:\n");
    printGraph(graph);

    freeGraph(graph);

    return 0;
}

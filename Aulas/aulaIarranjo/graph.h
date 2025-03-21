#ifndef GRAPH_H
#define GRAPH_H

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct {
    int numVertices;
    Node** adjacencyList;
} Graph;

// Function declarations
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);

#endif

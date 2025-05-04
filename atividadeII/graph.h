#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct Vertex {
    int id;
    bool visitado;
} Vertex;

typedef struct {
    int Vertices;
    int Arestas;
    int** adj;        // matriz de adjacência [Vertices x Vertices]
    Vertex* vertices; // vetor de vértices com visitado e id
} Graph;

typedef struct {
    int Origem;
    int Destino;
} Arc;

Graph initGraph(int Vertices);
void destroyGraph(Graph graph);
void insertArc(Graph* graph, Arc arc);
void removeArc(Graph* graph, Arc arc);
void BFS(Graph* grafo, int inicio);
void DFS(Graph* grafo, int inicio);

#endif

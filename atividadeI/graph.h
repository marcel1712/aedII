#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int Origem;
    int Destino;
} Arc;

typedef struct {
    int Vertices;
    int Arestas;
    int** adj;
} Graph;

Graph initGraph(int Vertices);
void destroyGraph(Graph graph);
void insertArc(Graph* graph, Arc arc);
void removeArc(Graph* graph, Arc arc);
void printGraph(Graph graph);

#endif

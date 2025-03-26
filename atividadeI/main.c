#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph initGraph(int Vertices){
    Graph graph;
    graph.Vertices = Vertices;
    graph.Arestas = 0;

    //alocando matriz VxV
    graph.adj = malloc(Vertices * sizeof(int*)); //alocando o vetor de ponteiros [* * * * *]
    for (int i = 0; i < Vertices; i++) {
        graph.adj[i] = calloc(Vertices, sizeof(int)); //alocando V linhas em cada ponteiro dentro do vetor
    }

    return graph;
}

void destroyGraph(Graph graph){
    for (int i = 0; i < graph.Vertices; i++){
        free(graph.adj[i]);
    }
    free(graph.adj);
}

// função alterada para receber ponteiro
void insertArc(Graph* graph, Arc arc){
    if(graph->adj[arc.Origem][arc.Destino] == 0){
        graph->adj[arc.Origem][arc.Destino] = 1;
        graph->adj[arc.Destino][arc.Origem] = 1;
        graph->Arestas += 1;
    }
}

// função alterada para receber ponteiro
void removeArc(Graph* graph, Arc arc){
    if (graph->adj[arc.Origem][arc.Destino] == 1) {
        graph->adj[arc.Origem][arc.Destino] = 0;
        graph->adj[arc.Destino][arc.Origem] = 0;
        graph->Arestas -= 1;
    }
}

void printGraph(Graph graph){
    printf("Total of vertices: %d, total of arcs: %d\n", graph.Vertices, graph.Arestas);
    for(int i = 0; i < graph.Vertices; i++){
        printf("Vertex %d, arcs: ", i);

        int primeiro = 1; // flag para controlar a vírgula
        for (int j = 0; j < graph.Vertices; j++) {
            if (graph.adj[i][j] != 0) {
                if (!primeiro) {
                    printf(", ");
                }
                printf("%d", j);
                primeiro = 0;
            }
        }

        printf("\n");
    }
}


int main() {
    int V;
    scanf("%d", &V); // lê número de vértices

    Graph g = initGraph(V);

    int origem, destino;
    while (scanf("%d %d", &origem, &destino) == 2) {
        Arc a = {origem, destino};
        insertArc(&g, a); // passando endereço do grafo
    }

    printGraph(g);
    destroyGraph(g);
    return 0;
}

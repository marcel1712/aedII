#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph initGraph(int Vertices) {
    Graph graph;
    graph.Vertices = Vertices;
    graph.Arestas = 0;

    graph.adj = malloc(Vertices * sizeof(int*));
    if (graph.adj == NULL) {
        printf("Erro na alocação da matriz\n");
        exit(1);
    }

    for (int i = 0; i < Vertices; i++) {
        graph.adj[i] = calloc(Vertices, sizeof(int));
        if (graph.adj[i] == NULL) {
            printf("Erro na alocação da linha %d\n", i);
            exit(1);
        }
    }

    graph.vertices = malloc(Vertices * sizeof(Vertex));
    if (graph.vertices == NULL) {
        printf("Erro na alocação do vetor de vértices\n");
        exit(1);
    }

    for (int i = 0; i < Vertices; i++) {
        graph.vertices[i].id = i;
        graph.vertices[i].visitado = false;
    }

    return graph;
}

void destroyGraph(Graph graph) {
    for (int i = 0; i < graph.Vertices; i++) {
        free(graph.adj[i]);
    }
    free(graph.adj);
    free(graph.vertices);
}

void insertArc(Graph* graph, Arc arc) {
    if (arc.Origem < 0 || arc.Origem >= graph->Vertices ||
        arc.Destino < 0 || arc.Destino >= graph->Vertices) {
        printf("Erro: arco fora dos limites\n");
        return;
    }

    if (graph->adj[arc.Origem][arc.Destino] == 0) {
        graph->adj[arc.Origem][arc.Destino] = 1;
        graph->adj[arc.Destino][arc.Origem] = 1;
        graph->Arestas += 1;
    }
}

void removeArc(Graph* graph, Arc arc) {
    if (graph->adj[arc.Origem][arc.Destino] == 1) {
        graph->adj[arc.Origem][arc.Destino] = 0;
        graph->adj[arc.Destino][arc.Origem] = 0;
        graph->Arestas -= 1;
    }
}

void BFS(Graph* grafo, int inicio) {
    int fila[grafo->Vertices];
    int inicioFila = 0, fimFila = 0;

    for (int i = 0; i < grafo->Vertices; i++) {
        grafo->vertices[i].visitado = false;
    }

    grafo->vertices[inicio].visitado = true;
    fila[fimFila++] = inicio;

    while (inicioFila < fimFila) {
        int v = fila[inicioFila++];
        printf("visited %d \n", v);

        for (int w = 0; w < grafo->Vertices; w++) {
            if (grafo->adj[v][w] && !grafo->vertices[w].visitado) {
                grafo->vertices[w].visitado = true;
                fila[fimFila++] = w;
            }
        }
    }
}

void DFSUtil(Graph* grafo, int v) {
    grafo->vertices[v].visitado = true;
    printf("visited %d \n", v);

    for (int w = 0; w < grafo->Vertices; w++) {
        if (grafo->adj[v][w] && !grafo->vertices[w].visitado) {
            DFSUtil(grafo, w);
        }
    }
}

void DFS(Graph* grafo, int inicio) {
    for (int i = 0; i < grafo->Vertices; i++) {
        grafo->vertices[i].visitado = false;
    }
    DFSUtil(grafo, inicio);
}

int main() {
    int n;
    scanf("%d", &n);

    Graph grafo = initGraph(n);

    int origem, destino;
    while (scanf("%d %d", &origem, &destino) == 2) {
        Arc a;
        a.Origem = origem;
        a.Destino = destino;
        insertArc(&grafo, a);
    }

    printf("DFS\n");
    DFS(&grafo, 0);

    printf("BFS\n");
    BFS(&grafo, 0);

    destroyGraph(grafo);
    return 0;
}

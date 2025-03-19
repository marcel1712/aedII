#include <stdlib.h>
#include <stdio.h>

#define Vertex int

typedef struct {
    Vertex v;
    Vertex w;
} Arc;

struct arclist {
    int size;
    Arc *arcs;
};

typedef struct arclist *Graph;

// Inicializa o grafo vazio
Graph initGraph() {
    Graph G = (Graph)malloc(sizeof(*G));
    G->size = 0;
    G->arcs = NULL;
    return G;
}

// Cria um arco (aresta direcionada)
Arc newArc(Vertex v, Vertex w) {
    Arc a;
    a.v = v;
    a.w = w;
    return a;
}

// Insere um arco direcionado no grafo
void insertArc(Graph G, Vertex v, Vertex w) {
    Arc newa = newArc(v, w);
    G->size++;
    G->arcs = (Arc*)realloc(G->arcs, G->size * sizeof(Arc));

    if (G->arcs == NULL) {
        printf("Erro ao realocar memoria para os arcos.\n");
        exit(1);
    }

    G->arcs[G->size - 1] = newa;
}

// Insere uma aresta não direcionada (dois arcos)
void insertEdge(Graph G, Vertex v, Vertex w) {
    insertArc(G, v, w);
    insertArc(G, w, v);
}

// Imprime todos os arcos do grafo
void printGraph(Graph G) {
    printf("Graph with %d arcs:\n", G->size);

    for (int i = 0; i < G->size; i++) {
        printf("Arc %d: %d -> %d\n", i, G->arcs[i].v, G->arcs[i].w);
    }
}

// Remove um arco direcionado
void removeArc(Graph G, Vertex v, Vertex w) {
    for (int i = 0; i < G->size; i++) {
        if (G->arcs[i].v == v && G->arcs[i].w == w) {

            // Substitui pelo último arco e diminui o tamanho
            G->arcs[i] = G->arcs[G->size - 1];
            G->size--;

            // Opcional: Realocar para reduzir o espaço usado
            // G->arcs = realloc(G->arcs, G->size * sizeof(Arc));

            printf("Arco removido: %d -> %d\n", v, w);
            return; // remove só uma ocorrência
        }
    }
    printf("Arco %d -> %d não encontrado.\n", v, w);
}

// Remove uma aresta não direcionada (dois arcos)
void removeEdge(Graph G, Vertex v, Vertex w) {
    removeArc(G, v, w); // Remove v -> w
    removeArc(G, w, v); // Remove w -> v
}

// Libera a memória alocada para o grafo
void destroyGraph(Graph G) {
    if (G == NULL) return;

    free(G->arcs);
    free(G);
}

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Node newNode(Vertex value, Node next){
    Node a = malloc(sizeof(*a));
    a->value = value;
    a->next = next;
    return a;
}

Graph initGraph(int V){
    Graph G = malloc(sizeof(*G));
    G->V = V;
    G->A = 0;
    G->adj = malloc(V*sizeof(Node));
    for (int i; i < V;i++){
        G->adj[i] = NULL;
    }
    return G;
}

void insertArc(Graph G, Vertex v, Vertex w){
    for (Node p = G; p != NULL; p = p->next)
    {
        if(p->value == w){
            return;
        }
    }
    G->adj[v] = newNode(w, G->adj[v]);
    G->adj;
    
}

void removeArc(Graph G, Vertex v, Vertex w){
    Node *prev = &G->adj[v];
    Node p = G->adj[v];

    while(p != NULL){
        if(p->value == w){
            *prev = p->next;
            free(p);
            G->A --;
            return;
        }
    }
}

void printGraph(Graph G) {
    printf("Vertices: %d, Arcos: %d\n", G->V, G->A);
    for (int v = 0; v < G->V; v++) {
        printf("%d:", v);
        for (Node p = G->adj[v]; p != NULL; p = p->next) {
            printf(" -> %d", p->value);
        }
        printf("\n");
    }
}

// Libera a memória do grafo
void destroyGraph(Graph G) {
    if (G != NULL) {
        for (int v = 0; v < G->V; v++) {
            Node p = G->adj[v];
            while (p != NULL) {
                Node t = p;
                p = p->next;
                free(t);
            }
        }
        free(G->adj);
        free(G);
    }
}

int main() {
    int V = 5;
    Graph G = initGraph(V);

    insertArc(G, 0, 1);
    insertArc(G, 1, 2);
    insertArc(G, 2, 3);
    insertArc(G, 3, 4);
    insertArc(G, 4, 0);

    printf("Grafo inicial:\n");
    printGraph(G);

    printf("\nRemovendo arco 4 -> 0:\n");
    removeArc(G, 4, 0);
    printGraph(G);

    destroyGraph(G);

    return 0;
}
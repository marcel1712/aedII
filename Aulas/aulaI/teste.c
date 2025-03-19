#include <stdio.h>
#include "arclist.h"

int main() {
    printf("=== TESTE DE GRAFO ===\n");

    // Inicializa um grafo vazio
    Graph G = initGraph();
    if (G == NULL) {
        printf("Erro ao inicializar o grafo.\n");
        return 1;
    }

    printf("Grafo inicializado com sucesso!\n");

    // Insere algumas arestas
    printf("\nInserindo arestas...\n");
    insertEdge(G, 1, 2);
    insertEdge(G, 2, 3);
    insertEdge(G, 4, 1);
    insertArc(G, 5, 6); // só um arco direcionado

    // Imprime o estado atual do grafo
    printf("\nImprimindo o grafo:\n");
    printGraph(G);

    // Testando grafos com mais arestas
    printf("\nAdicionando mais arcos e arestas...\n");
    insertEdge(G, 7, 8);
    insertEdge(G, 8, 9);

    // Imprime novamente
    printf("\nImprimindo o grafo atualizado:\n");
    printGraph(G);

    // Destroi o grafo e libera memória
    printf("\nDestruindo o grafo...\n");
    destroyGraph(G);

    printf("Grafo destruído com sucesso!\n");

    return 0;
}

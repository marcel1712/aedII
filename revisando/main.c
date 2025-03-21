#include <stdio.h>
int main(void) {
    int n, i;
    char x[20], y[20];

    printf("Número de vértices: ");

    scanf("%d", &n);

    printf("Digite os pares de arestas relacionadas aos %d vértices. Digite -1 para terminar. \n", n);

    while (scanf("%d[^-1]20s %20s", &x, &y) == 2) {
        printf("Aresta: %s %s\n", x, y);
    }
    printf("fim.");
    return 0;
    }
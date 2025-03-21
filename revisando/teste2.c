//arquivo teste para ler um arquivo via terminal
#include <stdio.h>

int main(void) {
    int n, x, y;
    
    printf("Número de vértices: ");
    fflush(stdout);  // Para garantir que imprima antes de digitar

    if (scanf("%d", &n) == 1) {
        printf("Vértices: %d\n", n);
        
        while (scanf("%d %d", &x, &y) != EOF) {
            printf("Arco: %d %d\n", x, y);
        }
    }

    printf("fim.\n");
    return 0;
}

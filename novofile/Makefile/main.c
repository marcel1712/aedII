#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int dado;
    struct Node* next;
    struct Node* previous;
} Node;

typedef struct ListaEncadeada {
    Node* head;
    Node* end;
    int size;
} ListaEncadeada;

// Funções
ListaEncadeada* criarLista();
Node* criarNode(int value);
void insertHead(ListaEncadeada* lista, int value);
void insertEnd(ListaEncadeada* lista, int value);
void insertIndexValue(ListaEncadeada* lista, int value, int index);
void printLista(ListaEncadeada* lista);

// Criação da lista encadeada
ListaEncadeada* criarLista() {
    ListaEncadeada* lista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    lista->head = NULL;
    lista->end = NULL;
    lista->size = 0;
    return lista;
}

Node* criarNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->dado = value;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

// Inserção no início (HEAD)
void insertHead(ListaEncadeada* lista, int value) {
    Node* node = criarNode(value);
    if (lista->size == 0) {
        lista->head = node;
        lista->end = node;
    } else {
        node->next = lista->head;
        lista->head->previous = node;
        lista->head = node;
    }
    lista->size++;
}

// Inserção no final (END/TAIL)
void insertEnd(ListaEncadeada* lista, int value) {
    Node* node = criarNode(value);
    if (lista->size == 0) {
        lista->head = node;
        lista->end = node;
    } else {
        node->previous = lista->end;
        lista->end->next = node;
        lista->end = node;
    }
    lista->size++;
}

// Inserção em índice específico (INDEX)
void insertIndexValue(ListaEncadeada* lista, int value, int index) {
    if (index < 0 || index > lista->size) {
        return;  // índice inválido
    }

    if (index == 0) {
        insertHead(lista, value);
        return;
    }

    if (index == lista->size) {
        insertEnd(lista, value);
        return;
    }

    Node* node = criarNode(value);
    Node* atual = lista->head;

    // Avança até o índice desejado
    for (int i = 0; i < index; i++) {
        atual = atual->next;
    }

    Node* anterior = atual->previous;

    node->next = atual;
    node->previous = anterior;
    anterior->next = node;
    atual->previous = node;

    lista->size++;
}

// Impressão no formato exato dos testes
void printLista(ListaEncadeada* lista) {
    if (lista->size == 0) return;

    Node* atual = lista->head;
    int index = 0;

    // Imprime HEAD
    printf("Head -> Data: %d", atual->dado);
    if (atual->next != NULL) {
        printf(", Next: %d\n", atual->next->dado);
    } else {
        printf("\n");
    }

    atual = atual->next;

    // Imprime cada Node
    while (atual != NULL) {
        printf("Node %d -> Previous: %d, Data: %d", index + 1,
               atual->previous->dado,
               atual->dado);

        if (atual->next != NULL) {
            printf(", Next: %d\n", atual->next->dado);
        } else {
            printf("\n");
        }

        atual = atual->next;
        index++;
    }
}

int main() {
    int qtdComandos;
    scanf("%d", &qtdComandos);
    getchar();  // Consome o '\n'

    ListaEncadeada* lista = criarLista();

    char comando[100];
    for (int i = 0; i < qtdComandos; i++) {
        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = '\0';  // remove '\n'

        if (strncmp(comando, "INSERT HEAD", 11) == 0) {
            int value;
            sscanf(comando + 12, "%d", &value);
            insertHead(lista, value);
        } else if (strncmp(comando, "INSERT INDEX", 12) == 0) {
            int index, value;
            sscanf(comando + 13, "%d %d", &index, &value);
            insertIndexValue(lista, value, index);
        } else if (strncmp(comando, "INSERT END", 10) == 0 || strncmp(comando, "INSERT TAIL", 11) == 0) {
            int value;
            sscanf(comando + 11, "%d", &value);
            insertEnd(lista, value);
        }
    }

    printLista(lista);

    // Liberação da memória
    Node* atual = lista->head;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->next;
        free(temp);
    }
    free(lista);

    return 0;
}

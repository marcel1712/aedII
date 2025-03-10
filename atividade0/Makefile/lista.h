#ifndef LISTA_H
#define LISTA_H

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

#endif

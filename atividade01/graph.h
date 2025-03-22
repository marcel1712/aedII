#include <stdio.h>

typedef struct Node{

    struct Node* next;
}Node

struct graph
{
    int V; //tamanho da matriz
    int A; //grafos inseridos

}

Graph initGraph();
void destroyGraph(Graph);
void insertGraph(Graph, Arc);
void removeArc(Graph, Arc);
void printGraph(Graph);
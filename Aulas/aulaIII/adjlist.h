#include <stdio.h>
#include <stdlib.h>

#define Vertex int

typedef struct node_struct *Node;

typedef struct{
    int origem;
    int destino;
    int peso;
}Arc


struct node_struct{
    Vertex value;
    Node next;
};

struct graph
{
    int V;
    int A;
    Node *node;
};



typedef struct 
{
    /* data */
};

Graph initGraph(int V){
    Graph G = (Graph)malloc(sizeof(*G));
    Gs
}


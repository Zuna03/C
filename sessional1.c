#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define SIZE 10

struct adjacencyListNodes
{
    int des;
    int atm_id;
    int loc_id;
    char atm_name[20];
    char bank_name[20];
    int bank_id;
    struct adjacencyListNodes *next;
};

struct adjacencyList
{
    struct adjacencyListNodes *head;
};

struct graph
{
    int v;
    struct adjacencyList *arr;
};

struct adjacencyListNodes *createNode(int des, int a, int l, char *an, char *bn, int bi)
{
    struct adjacencyListNodes *newNode = (struct adjacencyListNodes *)malloc(sizeof(struct adjacencyListNodes));
    newNode->des = des;
    newNode->atm_id = a;
    newNode->loc_id = l;
    strcpy(newNode->atm_name, an);
    strcpy(newNode->bank_name, bn);
    newNode->bank_id = bi;
    newNode->next = NULL;

    return newNode;
}

struct graph *creategraph(int vertex)
{
    struct graph *newgraph = (struct graph *)malloc(sizeof(struct graph));
    newgraph->v = vertex;
    newgraph->arr = (struct adjacencyList *)malloc(vertex * sizeof(struct adjacencyList));

    for (int i = 0; i < vertex; i++)
    {
        newgraph->arr[i].head = NULL;
    }

    return newgraph;
}

void addEdge(struct graph *newgraph, int src, int dest, int a, int l, char *an, char *bn, int bi)
{
    struct adjacencyListNodes *newNode = createNode(dest, a, l, an, bn, bi);
    newNode->next = newgraph->arr[src].head;
    newgraph->arr[src].head = newNode;

    newNode = createNode(src, a, l, an, bn, bi);
    newNode->next = newgraph->arr[dest].head;
    newgraph->arr[dest].head = newNode;
}

void printgraph(struct graph *graph)
{
    int v;
    for (v = 0; v < graph->v; ++v)
    {
        struct adjacencyListNodes *move = graph->arr[v].head;
        printf("\nAdjacency list of vertex %d\n", v);
        while (move)
        {
            printf("head->");
            printf("%d\n", move->des);
            printf("%d\n", move->atm_id);
            printf("%d\n", move->loc_id);
            printf("%s\n", move->atm_name);
            printf("%s\n", move->bank_name);
            printf("%d\n", move->bank_id);
            printf("-------------------------\n");
            move = move->next;
        }
        printf("\n");
    }
}

void delete (struct graph *graph, int ai)
{
    int v;
    for (v = 0; v < graph->v; ++v)
    {
        struct adjacencyListNodes *move = graph->arr[v].head;
        struct adjacencyListNodes *move2;
        while (move && move->atm_id != ai)
        {
            move2 = move;
            move = move->next;
        }
        if (move == NULL)
            move2->next = NULL;
        else
        {
            move2->next = move->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 5;
    struct graph *graph = creategraph(V);
    addEdge(graph, 0, 1, 1001, 1001, "SBI", "Raipur", 1000);
    addEdge(graph, 0, 4, 1041, 10012, "HDFC1", "Kaashi", 10201);
    addEdge(graph, 1, 2, 1031, 10022, "HDFC2", "Mumbai", 10101);
    addEdge(graph, 1, 3, 1021, 10032, "HDFC3", "Delhi", 10301);
    // addEdge(graph, 0, 4);
    // addEdge(graph, 1, 2);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 1, 4);
    // addEdge(graph, 2, 3);
    // addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printgraph(graph);
    
    delete (graph, 1001);
    printf("After deleting\n");
    printgraph(graph);
    return 0;
}
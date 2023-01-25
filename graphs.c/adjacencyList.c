#include <stdio.h>
#include <stdlib.h>

struct adjacencyListNodes
{
    int dest;
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

struct adjacencyListNodes *createNode(int v)
{
    struct adjacencyListNodes *newNode = (struct adjacencyListNodes *)malloc(sizeof(struct adjacencyListNodes));
    newNode->dest = v;
    newNode->next = NULL;

    return newNode;
}

struct graph *createGraph(int vertex)
{
    struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
    newGraph->v = vertex;
    newGraph->arr = (struct adjacencyList *)malloc(vertex * sizeof(struct adjacencyList));

    for (int i = 0; i < vertex; i++)
    {
        newGraph->arr[i].head = NULL;
    }

    return newGraph;
}

void addEdge(struct graph *newGraph, int src, int dest)
{
    struct adjacencyListNodes *newNode = createNode(dest);
    newNode->next = newGraph->arr[src].head;
    newGraph->arr[src].head = newNode;

    newNode = createNode(src);
    newNode->next = newGraph->arr[dest].head;
    newGraph->arr[dest].head = newNode;
}

void printGraph(struct graph *graph)
{
    int v;
    for (v = 0; v < graph->v; ++v)
    {
        struct adjacencyListNodes *pCrawl = graph->arr[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 5;
    struct graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_198 Node_198;

typedef struct QueNode_198
{
    Node_198 *data_198;
    struct QueNode_198 *link_198;
} QueNode_198;

typedef struct Queue_198
{
    QueNode_198 *front_198;
    QueNode_198 *rear_198;
} Queue_198;

int isEmpty_198(Queue_198 *que_198)
{
    if (que_198->front_198 == NULL)
        return 1;
    return 0;
}

void enqueue_198(Queue_198 *que_198, Node_198 *data_198)
{
    QueNode_198 *temp_198 = (QueNode_198 *)malloc(sizeof(QueNode_198));
    temp_198->data_198 = data_198;
    temp_198->link_198 = NULL;

    if (isEmpty_198(que_198))
    {
        que_198->front_198 = que_198->rear_198 = temp_198;
        return;
    }

    que_198->rear_198->link_198 = temp_198;
    que_198->rear_198 = que_198->rear_198->link_198;
}

Node_198 *dequeue_198(Queue_198 *que_198)
{
    if (isEmpty_198(que_198))
        return NULL;

    QueNode_198 *temp_198 = que_198->front_198;
    que_198->front_198 = que_198->front_198->link_198;

    if (que_198->front_198 == NULL)
        que_198->rear_198 = NULL;

    Node_198 *n_198 = temp_198->data_198;
    free(temp_198);
    return n_198;
}

Node_198 *peek_198(Queue_198 *que_198)
{
    if (isEmpty_198(que_198))
        return NULL;
    return que_198->front_198->data_198;
}

struct Edge_198;
typedef struct Node_198
{
    int Atm_ID, Bank_ID, location;
    char atm_name[100], bank_name[100];
    int visited_status_198;
    struct Edge_198 *edges_198;
    struct Node_198 *link_198;
} Node_198;
typedef struct Edge_198
{
    struct Node_198 *dest_198;
    struct Edge_198 *link_198;
} Edge_198;
typedef struct graph_198
{
    int size_198;
    struct Node_198 *start_198;
} graph_198;
void add_node_198(graph_198 *);
void insert_edges_198(graph_198 *, int, int);
void display_198(graph_198);

void delete_198(graph_198 *graph_198);

int main()
{
    printf("Note: The graphs are directed and 1 based indexed!\n");
    printf("There can be more than one edge between a source and a destination.\n\n");
    graph_198 graph_198 = {0, NULL};
    int choice_198;
    unsigned int vartex_1_198, vartex_2_198;
    do
    {
        printf("Current amount of nodes in graph: (%d)\n", graph_198.size_198);
        printf("1) Add a Node\n2) Add an edge\n");
        printf("3) Display raw structure\n"
               "4) To Delete a Node 5) Exit\n->: ");
        scanf("%d", &choice_198);
        printf("\n");
        switch (choice_198)
        {
        case 1:
            add_node_198(&graph_198);
            break;
        case 2:
            printf("\nEnter the pair of vertices ");
            printf("(To and From, space separated): ");
            scanf("%d%d", &vartex_1_198, &vartex_2_198);
            insert_edges_198(&graph_198, vartex_1_198, vartex_2_198);
            break;
        case 3:
            display_198(graph_198);
            break;
        case 4:
            delete_198(&graph_198);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------------\n");
    } while (choice_198 >= 1 && choice_198 < 6);
    return 0;
}

void delete_198(graph_198 *graph_198)
{
    printf("Enter Atm ID of bank to be deleted : ");
    int id;
    scanf("%d", &id);
    struct Node_198 *tp = graph_198->start_198;
    while (graph_198->start_198)
    {
        if (graph_198->start_198->Atm_ID == id)
        {
            struct Node_198 *t = graph_198->start_198;
            tp->link_198 = graph_198->start_198->link_198;
            free(t);
        }
        tp->link_198 = graph_198->start_198;
        graph_198->start_198 = graph_198->start_198->link_198;
    }
}

void add_node_198(graph_198 *graph_198)
{
    Node_198 *lastNode_198 = graph_198->start_198;
    if (!lastNode_198)
    {
        graph_198->size_198++;
        graph_198->start_198 = (Node_198 *)malloc(sizeof(Node_198));
        graph_198->start_198->location = graph_198->size_198;
        printf("Enter Bank_ID ATM_ID : ");
        scanf("%d", &graph_198->start_198->Bank_ID);
        scanf("%d", &graph_198->start_198->Atm_ID);
        printf("Enter Bank_Name ATM_Name : ");
        scanf("%s", graph_198->start_198->bank_name);
        scanf("%s", graph_198->start_198->atm_name);
        graph_198->start_198->edges_198 = NULL;
        graph_198->start_198->link_198 = NULL;
        return;
    }
    while (lastNode_198->link_198)
        lastNode_198 = lastNode_198->link_198;
    lastNode_198->link_198 = (Node_198 *)malloc(sizeof(Node_198));
    lastNode_198->link_198->location = ++graph_198->size_198;
    printf("Enter Bank_ID ATM_ID : ");
    scanf("%d", &lastNode_198->link_198->Bank_ID);
    scanf("%d", &lastNode_198->link_198->Atm_ID);
    printf("Enter Bank_Name ATM_Name : ");
    scanf("%s", lastNode_198->link_198->bank_name);
    scanf("%s", lastNode_198->link_198->atm_name);
    lastNode_198->link_198->edges_198 = NULL;
    lastNode_198->link_198->link_198 = NULL;
}
void insert_edges_util(struct graph_198 graph_198, struct Node_198 *node_198, int vartex_2_198)
{
    if (vartex_2_198 < 1 || vartex_2_198 > graph_198)
        return;
    struct Node_198 *start_198 = graph_198->start_198;
    while (start_198)
    {
        if (start_198->location == vartex_2_198)
        {
            struct Node_198 *temp_node = node_198;
            struct Edge_198 temp_198 = (struct Edge_198*)malloc(sizeof(Edge_198));
            temp_198->dest_198 = start_198;
            temp_198->link_198 = NULL;
            if (!temp_node->edges_198)
            {
                temp_node->edges_198 = temp_198;
                return;
            }
            while (temp_node->edges_198->link_198)
                temp_node->edges_198 = temp_node->edges_198->link_198;
            temp_node->edges_198->link_198 = temp_198;
            return;
        }
        start_198 = start_198->link_198;
    }
}
void insert_edges_198(graph_198 *graph_198, int vartex_1_198, int vartex_2_198)
{
    if (vartex_1_198 < 1 || vartex_1_198 > graph_198->size_198)
        return;
    else if (vartex_2_198 < 1 || vartex_2_198 > graph_198->size_198)
        return;
    Node_198 *start_198 = graph_198->start_198;
    while (start_198)
    {
        if (start_198->location == vartex_1_198)
        {
            insert_edges_util(graph_198, &start_198, vartex_2_198);
            return;
        }
        start_198 = start_198->link_198;
    }
}

void display_198(graph_198 graph_198)
{
    while (graph_198.start_198)
    {
        printf("==============================\n"
               "location : %d\n"
               "ATM ID : %d\n"
               "Bank_ID : %d\n"
               "Bank Name : %s\n"
               "ATM name : %s\n "
               "==============================\n",
               graph_198.start_198->location, graph_198.start_198->Atm_ID,
               graph_198.start_198->Bank_ID, graph_198.start_198->bank_name, graph_198.start_198->atm_name);
        Edge_198 *edge = graph_198.start_198->edges_198;
        printf("Edges : ");
        while (edge)
        {
            printf("%d, ", edge->dest_198->location);
            edge = edge->link_198;
        }
        printf("\b\b \n");
        graph_198.start_198 = graph_198.start_198->link_198;
    }
    printf("\n");
}
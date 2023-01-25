// C code to implement Priority Queue
// using Linked List
#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct node_198
{
    int data;

    // Lower values indicate higher priority
    int priority_198;

    struct node_198 *next;

} Node;

// Function to Create A New Node
Node *newNode(int d, int p)
{
    Node *temp_198 = (Node *)malloc(sizeof(Node));
    temp_198->data = d;
    temp_198->priority_198 = p;
    temp_198->next = NULL;

    return temp_198;
}

// Return the value at head
int peek_198(Node **head)
{
    return (*head)->data;
}

// Removes the element with the
// highest priority form the list
void pop_198(Node **head)
{
    Node *temp_198 = *head;
    (*head) = (*head)->next;
    free(temp_198);
}

// Function to push according to priority
void push_198(Node **head, int d, int p)
{
    Node *start = (*head);

    // Create new Node
    Node *temp_198 = newNode(d, p);

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->priority_198 > p)
    {

        // Insert New Node before head
        temp_198->next = *head;
        (*head) = temp_198;
    }
    else
    {

        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
               start->next->priority_198 < p)
        {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        temp_198->next = start->next;
        start->next = temp_198;
    }
}

// Function to check is list is empty
int isEmpty_198(Node **head)
{
    return (*head) == NULL;
}

// Driver code
int main()
{
    // Create a Priority Queue
    // 7->4->5->6
    Node *pq = newNode(4, 1);
    push_198(&pq, 5, 2);
    push_198(&pq, 6, 3);
    push_198(&pq, 7, 0);

    while (!isEmpty_198(&pq))
    {
        printf("%d ", peek_198(&pq));
        pop_198(&pq);
    }

    return 0;
}

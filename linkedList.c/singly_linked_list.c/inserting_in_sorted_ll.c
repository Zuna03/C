#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void append_node_node(struct node **start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;

    struct node *temp;

    if (*start == NULL)
    {
        *start = new;
        return;
    }
    else
    {
        temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
}

void insert_sort(struct node *start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;

    struct node *temp;

    if (start == NULL || start->data >= n)
    {
        new->next = start;
        start = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = start;

            if (temp->next->data > n)
            {
                new->next = temp->next;
                temp->next = new;
                return;
            }
            temp = temp->next;
        }
    }
    if (temp->next == NULL)
    {
        new->next = NULL;
        temp->next = new;
    }
}

// 1) Program to  Print Current List :-

void display(struct node **start)
{

    struct node *temp = *start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *start = NULL;
    append_node_node(&start, 3);
    append_node_node(&start, 6);
    append_node_node(&start, 9);
    append_node_node(&start, 11);
    insert_sort(start, 1);
    display(&start);

    return 0;
}
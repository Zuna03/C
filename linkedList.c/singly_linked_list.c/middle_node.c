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

void middle_node(struct node *start)
{
    struct node *t = start;
    struct node *s = t;
    struct node *f = t;

    while (f->next != NULL && f->next->next != NULL)
    {
        f = f->next->next;
        s = s->next;
    }
    if (f->next == NULL)
    {
        printf("%d", s->data);
    }
    if (f->next->next == NULL)
    {
        printf("%d,%d", s->data, s->next->data);
    }
}

int main()
{
    struct node *start = NULL;
    append_node_node(&start, 1);
    append_node_node(&start, 2);
    append_node_node(&start, 3);
    append_node_node(&start, 4);
    append_node_node(&start, 5);
    append_node_node(&start, 6);
    append_node_node(&start, 7);
    middle_node(start);

    return 0;
}
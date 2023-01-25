#include <stdio.h>
#include <stdbool.h>
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

struct node *create_cycle(struct node *start, int k)
{
    struct node *t1 = start;
    struct node *t2;
    int i = 0;

    while (t1->next != NULL && t1->next != NULL)
    {
        if (i == k)
        {
            t2 = start;
        }
        t1 = t1->next;
        i++;
    }
    t1->next = t2;

    return start;
}

bool detect_cycle(struct node *start)
{
    struct node *t1 = start;
    struct node *t2 = start;

    while (t1 != NULL && t1->next != NULL)
    {
        t1 = t1->next->next;
        t2 = t2->next;

        if (t1 == t2)
        {
            return 1;
        }
    }
    return 0;
}

void remove_cycle(struct node *start)
{
    struct node *t1 = start;
    struct node *t2 = start;

    do
    {
        t1 = t1->next->next;
        t2 = t2->next;
    } while (t1 != t2);
    t1 = start;
    while (t1->next != t2->next)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    t2->next = NULL;
}

int main()
{
    struct node *start = NULL;
    append_node_node(&start, 1);
    append_node_node(&start, 2);
    append_node_node(&start, 3);
    append_node_node(&start, 4);
    append_node_node(&start, 5);

    create_cycle(start, 2);
    printf("%d\n", detect_cycle(start));

    remove_cycle(start);
    printf("%d", detect_cycle(start));

    return 0;
}
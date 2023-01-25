#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void creation(struct node **st, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = new;

    if (*st == NULL)
    {
        new->next = new;
        *st = new;
        return;
    }

    struct node *t = *st;
    while (t->next != *st)
    {
        t = t->next;
    }

    t->next = new;
    new->next = *st;
}

void print(struct node **st)
{
    struct node *t = *st;
    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != *st);
}
int main()
{
    struct node *st = NULL;

    creation(&st, 1);
    creation(&st, 2);
    creation(&st, 3);
    creation(&st, 4);

    print(&st);

    return 0;
}
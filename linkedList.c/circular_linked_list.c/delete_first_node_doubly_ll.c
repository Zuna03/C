#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void create(struct node **st, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = new;
    new->prev = new;

    if (*st == NULL)
    {
        new->next = new;
        new->prev = new;
        *st = new;
        return;
    }
    struct node *t = *st;
    while (t->next != *st)
    {
        t = t->next;
    }
    new->prev = t;
    new->next = (*st);
    t->next = new;
    (*st)->prev = new;
}

void print(struct node **st)
{
    struct node *t = (*st);
    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != (*st));
}

void delete (struct node **st)
{
    struct node *t = (*st);
    while (t->next != (*st))
    {
        t = t->next;
    }
    struct node *toDelete = *st;
    t->next = (*st)->next;
    (*st)->next->prev = t;
    *st = (*st)->next;
    free(toDelete);
}
int main()
{
    struct node *st = NULL;
    create(&st, 1);
    create(&st, 2);
    create(&st, 3);
    create(&st, 4);

    delete (&st);

    print(&st);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void create(struct node **st, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->prev = NULL;
    new->next = NULL;

    if (*st == NULL)
    {
        *st = new;
        return;
    }

    else
    {
        struct node *temp = *st;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new->prev = temp;
        temp->next = new;
    }
}

void adding_1st_node(struct node **st, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = (*st);
    new->prev = NULL;
    (*st)->prev = new;
    if ((*st) != NULL)
    {
        (*st)->prev = new;
    }
    (*st) = new;
}

void print(struct node **st, struct node **lt)
{
    struct node *t1 = *st;
    struct node *t2;

    printf("Forward traversal :- \n");
    while (t1 != NULL)
    {
        printf("%d ", t1->data);
        t2 = t1;
        t1 = t1->next;
    }
    printf("\n");

    printf("Backward traversal :- \n");
    while (t2 != NULL)
    {
        printf("%d ", t2->data);
        t2 = t2->prev;
    }
    printf("\n");
}

void display(struct node **start)
{

    struct node *temp = *start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void add_before(struct node **st, int n, int k)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;
    new->prev = NULL;

    struct node *t;

    if ((*st)->data == k)
    {
        new->next = (*st);
        if ((*st) != NULL)
        {
            (*st)->prev = new;
        }
        (*st) = new;
    }
    else
    {
        t = (*st);
        while (t->data != k)
        {
            t = t->next;
        }
        new->next = t;
        new->prev = t->prev;
        t->prev->next = new;
        t->prev = new;
    }
}

int main()
{
    struct node *st = NULL;
    struct node *lt = NULL;
    create(&st, 1);
    create(&st, 2);
    create(&st, 3);
    create(&st, 4);
    add_before(&st, 5, 4);

    print(&st, &lt);
    //display(&st);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void deLete(int n)
{
    // struct node *new = (struct node *)malloc(sizeof(struct node));

    // new->data = n;
    // new->next = NULL;
     struct node *temp;

    if (start->data == n)
    {
        struct node *todelete = start;
        start = todelete->next;
        free(todelete);
    }

    else
    {
        temp = start;
        while (temp->next->data != n)
        {
            temp = temp->next;
        }
        struct node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

void append_node(int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = n;
    new->next = NULL;

    struct node *temp;

    if (start == NULL)
    {
        start = new;
        return;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
}

void display()
{
    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    append_node(1);
    append_node(2);
    append_node(3);
    append_node(4);
    deLete(1);
    display();

    return 0;
}
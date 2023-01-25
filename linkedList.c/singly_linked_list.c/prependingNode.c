#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void prepend(int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = n;
    new->next = NULL;

    if (start == NULL)
    {
        start = new;
        return;
    }
    else
    {
        new->next = start;
        start = new;
    }
}

void display()
{
    struct node*temp;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}

int main()
{
    prepend(1);
    prepend(2);
    prepend(3);
    prepend(4);
    display();

    return 0;
}
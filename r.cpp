#include <bits/stdc++.h>

using namespace std;
struct node
{
    int item;
    char *name;
    struct node *next;
};

void create_node(struct node **start, int nu, char *str)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->item = nu;
    n->name = str;
    n->next = NULL;

    if (*start == NULL)
    {
        *start = n;
        return;
    }
    else
    {
        struct node *temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = NULL;
    }
}

void display(struct node **start)
{

    struct node *temp = *start;
    while (temp != NULL)
    {
        printf("%s ", temp->name);
        printf("%d ", temp->item);
        printf("\n");
        temp = temp->next;
    }
}
int main()
{
    struct node *start = NULL;
    char *s2;
    char c1[10];

    fgets(c1, 10, stdin);
    create_node(&start, 1, c1);
    fgets(c1, 10, stdin);
    create_node(&start, 2, c1);
    fgets(c1, 10, stdin);
    create_node(&start, 3, c1);
    display(&start);

    return 0;
}
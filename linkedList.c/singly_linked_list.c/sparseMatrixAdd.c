#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct node
{
    int row, col, data;
    struct node *next;
};

struct node *matrix_to_sparse(int **a, int n, int m)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->row = n;
    head->col = m;
    head->data = 0;
    head->next = NULL;
    struct node *temp = head;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                struct node *new = (struct node *)malloc(sizeof(struct node));
                new->row = i;
                new->col = j;
                new->data = a[i][j];
                new->next = NULL;
                temp->next = new;
                temp = temp->next;
                head->data++;
            }
        }
    }

    return head;
}

void print_sparse(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d %d %d\n", temp->row, temp->col, temp->data);
        temp = temp->next;
    }
}

struct node *add_sparse(struct node *sparse1, struct node *sparse2)
{
    struct node *ans = (struct node *)malloc(sizeof(struct node));
    ans->row = sparse1->row;
    ans->col = sparse1->col;
    ans->data = 0;
    ans->next = NULL;

    struct node *temp = ans;
    struct node *temp1 = sparse1->next;
    struct node *temp2 = sparse2->next;

    while (temp1 != NULL && temp2 != NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        if (temp1->row < temp2->row)
        {
            new->row = temp1->row;
            new->col = temp1->col;
            new->data = temp1->data;
            new->next = NULL;
            temp->next = new;
            temp = temp->next;
            temp1 = temp1->next;
            continue;
        }
        else if (temp2->row < temp1->row)
        {
            new->row = temp2->row;
            new->col = temp2->col;
            new->data = temp2->data;
            new->next = NULL;
            temp->next = new;
            temp = temp->next;
            temp2 = temp2->next;
            continue;
        }
        else if (temp1->row == temp2->row)
        {
            if (temp1->col < temp2->col)
            {
                new->row = temp1->row;
                new->col = temp1->col;
                new->data = temp1->data;
                new->next = NULL;
                temp->next = new;
                temp = temp->next;
                temp1 = temp1->next;
                continue;
            }
            else if (temp2->col < temp1->col)
            {
                new->row = temp2->row;
                new->col = temp2->col;
                new->data = temp2->data;
                new->next = NULL;
                temp->next = new;
                temp = temp->next;
                temp2 = temp2->next;
                continue;
            }
        }
        new->row = temp1->row;
        new->col = temp1->col;
        new->data = temp1->data + temp2->data;
        new->next = NULL;
        temp->next = new;
        temp = temp->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->row = temp1->row;
        new->col = temp1->col;
        new->data = temp1->data;
        new->next = NULL;
        temp->next = new;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->row = temp2->row;
        new->col = temp2->col;
        new->data = temp2->data;
        new->next = NULL;
        temp->next = new;
        temp = temp->next;
        temp2 = temp2->next;
    }

    return ans;
}

int main()
{
    int n, m;
    printf("Enter the number of rows :- ");
    scanf("%d", &n);

    printf("Enter the number of columns :- ");
    scanf("%d", &m);

    int **a = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        a[i] = (int *)malloc(sizeof(int) * m);

    int **b = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        b[i] = (int *)malloc(sizeof(int) * m);

    printf("Enter the elements for first 2d array :-\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }

    printf("Enter the elements for second 2d array :-\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);
    }

    struct node *sparse1 = matrix_to_sparse(a, n, m);
    struct node *sparse2 = matrix_to_sparse(b, n, m);

    printf("First sparse Matrix :-\n");
    print_sparse(sparse1);

    printf("Second sparse Matrix :-\n");
    print_sparse(sparse2);

    struct node *result = add_sparse(sparse1, sparse2);
    printf("The addition result is :-\n");
    print_sparse(result);

    return 0;
}
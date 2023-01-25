#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node **start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = new;

    struct node *temp;
    if (*start == NULL)
    {
        new->next = new;
        *start = new;
    }
    else
    {
        temp = *start;
        while (temp->next != *start)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = *start;
    }
}

void display(struct node **start)
{
    struct node *temp = *start;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != *start);
    printf("\n");
}

void add_first(struct node **start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = new;

    struct node *temp;
    if (*start == NULL)
    {
        *start = new;
        (*start)->next = *start;
    }
    else
    {
        temp = *start;

        while (temp->next != *start)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = *start;
        *start = new;
    }
}

void delete_first(struct node **start)
{
    struct node *temp = *start;

    while (temp->next != *start)
    {
        temp = temp->next;
    }
    struct node *toDelete = *start;
    *start = (*start)->next;
    temp->next = *start;
    free(toDelete);
}
int main()
{
    struct node *start = (struct node *)malloc(sizeof(struct node));
    printf("Enter first value :-\n");
    scanf("%d", &start->data);
    start->next = start;

    struct node *temp = start;

    int x = 1;
    while (true)
    {
        printf("Do you want to add other node 1/0 :-\n");
        scanf("%d", &x);

        if (x == 0)
        {
            break;
        }

        printf("Enter the value :-\n");
        int val;
        scanf("%d", &val);
        create(&temp, val);
        temp = temp->next;
    }

    printf("The entered linked list is :-\n");
    display(&start);

    int check = 1;

    printf("1. Traverse the list \n");
    printf("2. Add a node a first node\n");
    printf("3. Delete the first node\n");

    int choice;
    char ch;
    int n;

    do
    {
        printf("\nEnter your choice(1-3): ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("The linked list is :\n");
            display(&start);
            break;

        case 2:
            printf("Add value of new node you want to add :\n");
            scanf("%d", &n);
            add_first(&start, n);
            printf("The linked list is :\n");
            display(&start);
            break;

        case 3:
            delete_first(&start);
            printf("The linked list is :\n");
            display(&start);
            break;

        default:
            printf("\nYou entered a wrong choice!!");
            break;
        }
        printf("\n Do you want to enter more choice(Y/N): ");
        scanf("%s", &ch);
    } while (ch == 'Y' || ch == 'y');

    printf("The program is terminated\n");

    return 0;
}
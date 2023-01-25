#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Create the list
void create(struct node **start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->prev = NULL;
    new->next = NULL;

    struct node *temp;

    if ((*start) == NULL)
    {
        *start = new;
        return;
    }
    else
    {
        temp = (*start);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new->prev = temp;
        temp->next = new;
        new->next = NULL;
    }
}

//Traverse the list in forward direction
void display(struct node **start)
{
    struct node *temp = (*start);
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Traverse the list in backward direction
void traverse_backward(struct node **start)
{
    //struct node *t1 = *start;
    if (*start != NULL)
    {
        traverse_backward(&(*start)->next);
        printf("%d ", (*start)->data);
    }
}

//Add a node after a given data item
void add_after_data(struct node **start, int n, int k)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->prev = NULL;
    new->next = NULL;

    struct node *temp = (*start);

    while (temp->data != k && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        new->prev = temp;
        new->next = temp->next;
        temp->next = new;
        temp->next->prev = new;
    }
    else
    {
        new->prev = temp;
        temp->next = new;
        new->next = NULL;
    }
}

//Add a node before a given data item
void add_before_data(struct node **start, int n, int k)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->prev = NULL;
    new->next = NULL;

    struct node *temp;
    if ((*start)->data == k)
    {
        new->next = (*start);
        (*start)->prev = new;
        *start = new;
        return;
    }
    else
    {
        temp = (*start);
        while (temp->next->data != k)
        {
            temp = temp->next;
        }
        new->prev = temp;
        new->next = temp->next;
        temp->next = new;
        temp->next->prev = new;
    }
}

//Delete a node at a given position
void delete_at_given(struct node **start, int pos)
{
    struct node *temp;
    int i = 1;
    if (pos == 1)
    {
        struct node *toDelete = *start;
        *start = (*start)->next;
        (*start)->prev = NULL;
        free(toDelete);
    }
    else
    {
        temp = *start;
        while (temp->next != NULL && i < pos)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next != NULL)
        {
            struct node *toDelete = temp;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(toDelete);
        }
        else
        {
            struct node *toDelete = temp;
            temp->prev->next = NULL;
            temp->prev = NULL;
            free(toDelete);
        }
    }
}

//Add a node a first node
void add_first(struct node **start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->prev = NULL;
    new->next = *start;
    (*start)->prev = new;
    *start = new;
}

//Delete the first node
void delete_first(struct node **start)
{
    struct node *toDelete = *start;
    *start = (*start)->next;
    (*start)->prev = NULL;
    free(toDelete);
}

//Reverse the content of the linked list by traversing each node only once.
void reverse(struct node **start)
{
    struct node *curr = *start;
    struct node *p = NULL;
    struct node *n;

    while (curr != NULL)
    {
        n = curr->next;
        curr->next = p;
        curr->prev = n;
        p = curr;
        curr = n;
    }
    *start = p;
}

int main()
{
    struct node *start = (struct node *)malloc(sizeof(struct node));
    printf("Enter first value :-\n");
    scanf("%d", &start->data);
    start->next = NULL;

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

    printf("1. Traverse the list in forward direction\n");
    printf("2. Traverse the list in backward direction\n");
    printf("3. Add a node after a given data item\n");
    printf("4. Add a node before a given data item\n");
    printf("5. Delete a node at a given position\n");
    printf("6. Add a node a first node\n");
    printf("7. Delete the first node\n");
    printf("8. Reverse the content of the linked list by traversing each node only once.\n");

    int choice;
    char ch;
    int n, n1, n2, k, k1, k2, p;
    do
    {
        printf("\nEnter your choice(1-8): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The linked list is :\n");
            display(&start);
            break;

        case 2:
            printf("The reverse linked list is :\n");
            traverse_backward(&start);
            break;

        case 3:
            printf("Add value of new node you want to add :\n");
            scanf("%d", &n);
            printf("Enter value of node after which you want new node to be added :\n");
            scanf("%d", &k);
            add_after_data(&start, n, k);
            printf("The linked list is :\n");
            display(&start);
            break;

        case 4:
            printf("Add value of new node you want to add :\n");
            scanf("%d", &n1);
            printf("Enter value of node before which you want new node to be added :\n");
            scanf("%d", &k1);
            add_before_data(&start, n, k);
            printf("The linked list is :\n");
            display(&start);
            break;

        case 5:
            printf("Enter the position after which you want new node to be deleted :\n");
            scanf("%d", &p);
            delete_at_given(&start, p);
            printf("The linked list is :\n");
            display(&start);
            break;

        case 6:
            printf("Add value of new node you want to add :\n");
            scanf("%d", &n2);
            add_first(&start, n2);
            printf("The linked list is :\n");
            display(&start);
            break;

        case 7:
            delete_first(&start);
            printf("The linked list is :\n");
            display(&start);
            break;

        case 8:
            reverse(&start);
            printf("The linked list with reverse content  is :\n");
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
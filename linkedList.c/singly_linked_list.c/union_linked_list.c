#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_node(struct node **head, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;

    struct node *temp;

    if (*head == NULL)
    {
        *head = new;
        return;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        // new->next = NULL;
    }
}

void duplicates(struct node**start)
{
    struct node *t1 = *start;
    struct node *t2;

    while (t1 != NULL && t1->next != NULL)
    {
        while ( t2->next != NULL)
        {
            if (t1->data == t2->next->data)
            {
                struct node *toDelete = t2->next;
                t2->next = t2->next->next;
                free(toDelete);
            }
            else
            {
                t2=t2->next;
            }
            
        }
        t1=t1->next;
    }
}

struct node *unIon(struct node *s1, struct node *s2, struct node **s3)
{
    while (s1 != NULL)
    {
        create_node(s3, s1->data);
        s1 = s1->next;
    }

    while (s2 != NULL)
    {
        create_node(s3, s2->data);
        s2 = s2->next;
    }
    duplicates(s3);

}

// 1) Program to  Print Current List :-

void display(struct node *head)
{

    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    create_node(&head, 1);
    create_node(&head, 2);
    create_node(&head, 3);
    create_node(&head, 4);
    create_node(&head, 5);
    create_node(&head, 6);
    display(head);

    struct node *head1 = NULL;
    create_node(&head1, 4);
    create_node(&head1, 3);
    create_node(&head1, 1);
    create_node(&head1, 5);
    create_node(&head1, 7);
    display(head1);

    struct node *s3 = NULL;
    unIon(head, head1, &s3);
    display(s3);

    return 0;
}
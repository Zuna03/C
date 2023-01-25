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

// 1) Program to  Print Current List :-

void display(struct node *head)
{

    // struct node *temp =head;
    // while (temp != NULL)
    // {
    //     printf("%d ", temp->data);
    //     temp = temp->next;
    // }
    if (head == NULL)
        return;
    //display(head->next);
    printf("%d ", head->data);
    display(head->next->next);
}
    
    

int main()
{
    struct node *head = NULL;
    create_node(&head, 1);
    create_node(&head, 2);
    create_node(&head, 3);
    create_node(&head, 4);
    create_node(&head, 5);
    display(head);

    return 0;
}
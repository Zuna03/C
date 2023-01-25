#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};


void append_node_node(struct node **start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;

    struct node *temp;

    if (*start == NULL)
    {
        *start = new;
        return;
    }
    else
    {
        temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
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

void check_palindrome(struct node* start)
{
    struct node* temp1=start;
    if(temp1->next==NULL)
    {
        return;
    }
    check_palindrome();
}


int main()
{
    struct node* start = NULL;
    append_node_node(&start,1);
    append_node_node(&start,2);
    append_node_node(&start,3);
    append_node_node(&start,4);
    display(&start);

    return 0;
}
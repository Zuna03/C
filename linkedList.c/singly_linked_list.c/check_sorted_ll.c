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

bool is_sorted(struct node* start)
{
    struct node* t1=start;
    struct node* t2;

    while (t1->next != NULL)
    {
        t2=t1->next;
        while (t2 != NULL)
        {
            if(t1->data > t2->data)
            {
                return 0;
            }
            t2=t2->next;
        }
        t1=t1->next;
        
    }
    return 1;
}

// 1) Program to  Print Current List :-

void display(struct node **start)
{

    struct node *temp = *start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


int main()
{
    struct node* start = NULL;
    append_node_node(&start,1);
    append_node_node(&start,2);
    append_node_node(&start,3);
    append_node_node(&start,-1);
    //display(&start);
    printf("%d\n",is_sorted(start));

    return 0;
}
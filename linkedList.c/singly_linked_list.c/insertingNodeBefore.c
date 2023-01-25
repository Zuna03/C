#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert(int x, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = n;
    new->next = NULL;

    struct node *temp;
    // struct node *temp1;
    // struct node *temp2;

    if (start->data == x)
    {
        new->next=start;  
        start=new;
        return ;
    }
    else
     {
    //      temp1=temp2=start;
    //     while (temp->data != x)
    //     {
    //         temp1=temp2;
    //         temp1=temp1->next;
    //     }
    //     temp2->next=new;
    //     new->next=temp1;
        temp = start;
        while (temp->next->data != x)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
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
    insert(2,5);
    display();

    return 0;
}
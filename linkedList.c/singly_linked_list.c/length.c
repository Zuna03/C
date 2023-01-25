#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void append_node(int n)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));

    new->data=n;
    new->next=NULL;

    struct node* temp;

    if(start == NULL)
    {
        start=new;
        return;
    }
    else
    {
        temp=start;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=NULL;
        
    }
}

void lengTh()
{
    int lengTH=0;
    struct node* temp=start;
    while (temp != NULL)
    {
        lengTH++;
        temp=temp->next;
    }
    printf("%d",lengTH);
}

int main()
{
    append_node(1);
    append_node(2);
    append_node(3);
    append_node(4);
    lengTh();

    return 0;
}
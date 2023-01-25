#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void sWap(int &a,int &b)
{
    int* temp=a;
    a=b;
    b=temp;
}
void selection_sort()
{
    struct node* t1=start;
    struct node* t2;

    while (t1 != NULL)
    {
        for(t2=t1->next;t2!=NULL;t2=t2->next)
        {
            if(t1->data > t2->data)
            {
                sWap(t1->data,t2->data);
            }
            t1=t1->next;
        }
    }
    
}
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

void display()
{
    struct node* temp=start;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    

}

int main()
{
    append_node(7);
    append_node(2);
    append_node(9);
    append_node(11);
    selection_sort();
    display();

    return 0;
}
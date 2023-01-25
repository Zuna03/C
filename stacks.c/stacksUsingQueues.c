#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

void insert(struct stack **s, int n)
{
    struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    new->data = n;
    new->next = *s;
    *s = new;
}

int delete(struct stack** s)
{
    struct stack* temp=*s;
    if(*s==NULL)
    return -1;
    else
    {
        while (temp->next!=NULL)
        {
            
        }
        
    }
}
int main()
{

    return 0;
}
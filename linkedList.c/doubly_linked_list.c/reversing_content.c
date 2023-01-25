#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void create(struct node **st, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->prev = NULL;
    new->next = NULL;

    if (*st == NULL)
    {
        *st = new;
        return;
    }

    else
    {
        struct node *temp = *st;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new->prev = temp;
        temp->next = new;
    }
}

void printList(struct node *st)
{
  while(st!=NULL)
  {
   printf("%d ", st->data);
   st = st->next;
  }
}

void reverse(struct node **st)
{
     struct node *temp = NULL; 
     struct node *curr = *st;
      
     while (curr !=  NULL)
     {
       temp = curr->prev;
       curr->prev = curr->next;
       curr->next = temp;             
       curr = curr->prev;
     }  

     if(temp != NULL)
     {
        *st=temp->prev;
     }   
}

int main()
{
    struct node *st = NULL;
    create(&st, 1);
    create(&st, 2);
    create(&st, 3);
    create(&st, 4);
    create(&st, 5);
    reverse(&st);
    printList(st);

    return 0;
}
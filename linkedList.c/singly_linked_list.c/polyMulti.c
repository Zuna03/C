#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;
};

void create(struct node **start, int c, int e)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->coeff = c;
    new->expo = e;
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

void duplicates(struct node **start)
{
    struct node *temp1 = *start;
    struct node *temp2;
    struct node *dup;

    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp1;
        while (temp2->next != NULL)
        {
            if (temp1->expo == temp2->next->expo)
            {
                temp1->coeff = temp1->coeff + temp2->next->coeff;
                dup = temp2->next;
                temp2->next = temp2->next->next;
                free(dup);
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}
void multiply(struct node *start1, struct node *start2, struct node **start3)
{
    struct node *temp1 = start1;
    struct node *temp2 = start2;
    int sum1 = 0;
    while (temp1 != NULL)
    {
        // int coeff, expo;
        while (temp2 != NULL)
        {
            create(start3, temp1->coeff * temp2->coeff, temp1->expo + temp2->expo);
            temp2 = temp2->next;
        }
        temp2 = start2;
        temp1 = temp1->next;
    }
    duplicates(start3);
}

void display(struct node *start)
{
    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%dx^%d + ", temp->coeff, temp->expo);
        temp = temp->next;
    }
    printf("0");
    printf("\n");
}
int main()
{
    printf("Enter the values for the first polynomial :- \n");
    printf("\n*****************************************************************\n");
    struct node *start1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter a coefficient :- ");
    scanf("%d", &start1->coeff);
    printf("Enter the exponent :- ");
    scanf("%d", &start1->expo);
    start1->next = NULL;
    int x1 = 1;
    struct node *temp1 = start1;
    while (true)
    {
        printf("Do you want to continue (1 = YES/ 0 = NO) :- ");
        scanf("%d", &x1);
        if (x1 == 0)
            break;
        int coe1;
        printf("Enter a coefficient :- ");
        scanf("%d", &coe1);
        int ex1;
        printf("Enter a exponent :- ");
        scanf("%d", &ex1);
        create(&temp1, coe1, ex1);
        temp1 = temp1->next;
    }
    printf("The First Polynomial is :- \n");
    display(start1);
    printf("\n*****************************************************************\n");
    printf("Enter the values for the second polynomial :- \n");
    struct node *start2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter a coefficient :- ");
    scanf("%d", &start2->coeff);
    printf("Enter a exponent :- ");
    scanf("%d", &start2->expo);
    start2->next = NULL;
    int x2 = 1;
    struct node *temp2 = start2;
    while (true)
    {
        printf("Do you want to continue (1 = YES/ 0 = NO) :- ");
        scanf("%d", &x2);
        if (x2 == 0)
            break;
        int coe2;
        printf("Enter a coefficient :- ");
        scanf("%d", &coe2);
        int ex2;
        printf("Enter a exponent :- ");
        scanf("%d", &ex2);
        create(&temp2, coe2, ex2);
        temp2 = temp2->next;
    }
    printf("The Second Polynomial is :- \n");
    display(start2);
    printf("\n*****************************************************************\n");
    struct node *head3 = NULL;
    multiply(start1, start2, &head3);
    printf("The equation is as follows :-\n");
    display(start1);
    printf(" * ");
    display(start2);
    printf(" = ");
    display(head3);
    printf("\n");
    return 0;
}
// #include <stdio.h>
// #define max 100

// struct stack
// {
//     int s[100];
//     int top;
// };

// void push1(struct stack *s1, struct stack *s2, int n)
// {
//     if (s1->top + 1 == s2->top || s1->top == max || s2->top == -1)
//     {
//         printf("Overflow\n");
//         return;
//     }
//     else
//     {
//         s1->top++;
//         s1->s[s1->top] = n;
//     }
// }

// void push2(struct stack *s1, struct stack *s2, int n)
// {
//     if (s1->top + 1 == s2->top || s1->top == max || s2->top == -1)
//     {
//         printf("Overflow\n");
//         return;
//     }
//     else
//     {
//         s2->top--;
//         s2->s[s2->top] = n;
//     }
// }

// int *pop1(struct stack *s1, int *b)
// {
//     if (s1->top == -1)
//     {
//         printf("Underflow\n");
//         return NULL;
//     }
//     else
//     {
//         *b = s1->s[s1->top];
//         s1->top--;
//     }
//     return b;
// }

// int *pop2(struct stack *s2, int *b)
// {
//     if (s2->top == max)
//     {
//         printf("Underflow\n");
//         return NULL;
//     }
//     else
//     {
//         *b = s2->s[s2->top];
//         s2->top++;
//     }
//     return b;
// }

// int main()
// {
//     struct stack s1;
//     s1.top = -1;

//     struct stack s2;
//     s2.top = max;

//     push1(&s1, &s2, 5);
//     push2(&s1, &s2, 10);
//     push2(&s1, &s2, 15);
//     push1(&s1, &s2, 11);
//     push2(&s1, &s2, 7);

//     int b = 0;
//     int *ans1 = pop1(&s1, &b);
//     printf("Popped element from stack 1 is : %d\n", *ans1);

//     int c = 0;
//     int *ans2 = pop1(&s2, &c);
//     printf("Popped element from stack 2 is : %d\n", *ans2);

//     return 0;
// }


//right
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Define the size of the array.
#define max 100
// Structure to create a stack ADT where 2 stacks are implemented for a array.
struct stack
{
    int top1, top2, data[max];
};
// Function to check whether a stack is full or not.
int isFull(struct stack *st)
{
    if ((st->top1 + 1) == st->top2)
        return 1;
    return 0;
}
// Functions for stack 1.
// Function to check whether a stack 1 is empty or not.
int isEmpty1(struct stack *st)
{
    if (st->top1 == -1)
        return 1;
    return 0;
}
// Function to push an item in the stack 1.
void pushStack1(struct stack *st, int val)
{
    if (isFull(st))
    {
        printf("Stack Full!!\n");
        return;
    }
    st->data[++st->top1] = val;
}
// Function to pop an item from the stack 1.
int popStack1(struct stack *st)
{
    if (isEmpty1(st))
    {
        printf("Stack Empty!!\n");
        return INT_MIN;
    }
    return st->data[st->top1--];
}
// Function to display the present stack 1.
void displayStack1(struct stack *st)
{
    if (isEmpty1(st))
        return;
    int val = popStack1(st);
    printf("%d ", val);
    displayStack1(st);
    pushStack1(st, val);
}
// Functions for stack 2.
// Function to check whether a stack 2 is empty or not.
int isEmpty2(struct stack *st)
{
    if (st->top2 == max)
        return 1;
    return 0;
}
// Function to push an item in the stack 2.
void pushStack2(struct stack *st, int val)
{
    if (isFull(st))
    {
        printf("Stack Full!!\n");
        return;
    }
    st->data[--st->top2] = val;
}
// Function to pop an item from the stack 2.
int popStack2(struct stack *st)
{
    if (isEmpty2(st))
    {
        printf("Stack Empty!!\n");
        return INT_MIN;
    }
    return st->data[st->top2++];
}
// Function to display the present stack 2.
void displayStack2(struct stack *st)
{
    if (isEmpty2(st))
        return;
    int val = popStack2(st);
    printf("%d ", val);
    displayStack2(st);
    pushStack2(st, val);
}
// Main Function.
int main()
{
    struct stack *st = (struct stack *)malloc(sizeof(struct
                                                                 stack));
    st->top1 = -1;
    st->top2 = max;
    int check = 1;

    printf("Stack ID:\n(1 == stack1)\t(2 == stack2)\n\n");
    printf("1.PUSH.\n");
    printf("2.POP.\n");
    printf("3.DISPLAY.\n");
    printf("4.QUIT!!\n");

    while (check)
    {

        printf("Enter your choice :- ");
        int z, id, val, popped;
        scanf("%d", &z);
        switch (z)
        {
        case 1:
            printf("Enter the stack ID :- ");
            scanf("%d", &id);
            printf("Enter the value :- ");
            scanf("%d", &val);
            if (id == 1)
                pushStack1(st, val);
            else
                pushStack2(st, val);
            printf("%d was pushed successfully in stack %d.\n", val,
                   id);
            break;
        case 2:
            printf("Enter the stack ID :- ");
            scanf("%d", &id);
            if (id == 1)
                popped = popStack1(st);
            else
                popped = popStack2(st);
            if (popped != INT_MIN)
                printf("%d was popped successfully from stack %d.\n",
                       popped, id);
            break;
        case 3:
            printf("Enter the stack ID :- ");
            scanf("%d", &id);
            if (id == 1)
            {
                printf("The current stack is :-\n");
                displayStack1(st);
                printf("\n");
            }
            else
            {
                printf("The current stack is :-\n");
                displayStack2(st);
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &check);

        if (check == 0)
        {
            break;
        }
    }

    printf("The Program is terminated!!\n");
    return 0;
}

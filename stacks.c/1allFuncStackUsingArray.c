#include <stdio.h>
#include <stdbool.h>

struct stack
{
    int s[100];
    int top;
};


// checking whether stack is full or not
bool isFull(struct stack *s1)
{
    if (s1->top == 99)
    {
        return true;
    }
    return false;
}

//pushing an element in stack
void push(struct stack *s1, int n)
{
    if (isFull(s1))
    {
        printf("Overflow\n");
        return;
    }

    s1->top++;
    s1->s[s1->top] = n;
}

bool isEmpty(struct stack *s1)
{
    if (s1->top == -1)
    {
        return true;
    }
    return false;
}

//popping element out of stack
void pop(struct stack *s1, int *b)
{
    if (isEmpty(s1))
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        *b = s1->s[s1->top];
        s1->top--;
    }
}

//adding elemnts in sorted order in sorted stack
void sorted_add(struct stack *s1, int x)
{
    if (s1->top == -1 || x > s1->s[s1->top])
    {
        push(s1, x);
        return;
    }
    int b;
    pop(s1, &b);
    sorted_add(s1, x);
    push(s1, b);
}

//sorting the stack
void sorting(struct stack *s1)
{
    int x;
    if (s1->top != -1)
    {
        pop(s1, &x);
        sorting(s1);
        sorted_add(s1, x);
    }
}

//displaying elements of stack
void display(struct stack *s1)
{
    if (s1->top == -1)
        return;
    int b = s1->s[s1->top];
    printf("%d  ", b);
    pop(s1, &b);
    display(s1);
    push(s1, b);
}

//copying one stack to other
void copy(struct stack *s1, struct stack *s2)
{
    if (s1->top == -1)
        return;
    int b = s1->s[s1->top];
    pop(s1, &b);
    copy(s1, s2);
    push(s2, b);
    push(s1, b);
}

int main()
{
    struct stack s1, s2;
    s1.top = -1;
    s2.top = -1;
    int ch;
    int b = 0;
    int c = 1;

    printf("1.Push element in stack\n");
    printf("2.Pop element from stack\n");
    printf("3.Display stack\n");
    printf("4.Copy one stack to other\n");
    printf("5.Sorting elements of stack\n");

    while (c)
    {
        printf("Enter your choice from 1-5\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element to be inserted \n");
            int a;
            scanf("%d", &a);
            push(&s1, a);
            printf("The number is pushed sucessfully\n");
            break;

        case 2:
            pop(&s1, &b);
            printf("The number is popped sucessfully\n");
            break;

        case 3:
            printf("The stack is\n");
            display(&s1);
            break;

        case 4:
            copy(&s1, &s2);
            printf("The copied stack is\n");
            display(&s2);
            break;

        case 5:
            sorting(&s1);
            printf("The sorted stack is\n");
            display(&s1);
            break;

        default:
            printf("invalid choice");
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &c);

        if (c == 0)
        {
            break;
        }
    }
    printf("The program is terminated !!\n");

    return 0;
}

#include <stdio.h>

struct stack
{
    int s[100];
    int top;
};

void push(struct stack *s1, int n)
{
    if (s1->top == 99)
        printf("Overflow\n");
    else
    {
        s1->top++;
        s1->s[s1->top] = n;
    }
}

void pop(struct stack *s1, int *b)
{
    if (s1->top == -1)
        printf("Underflow\n");
    else
    {
        *b = s1->s[s1->top];
        s1->top--;
    }
}

void display(struct stack *s1)
{
    if (s1->top == -1)
        return;
    int b = s1->s[s1->top];
    printf("%d ", b);
    pop(s1, &b);
    display(s1);
    push(s1, b);
}

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
    struct stack s1;
    s1.top = -1;

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    display(&s1);
    printf("\n");

    struct stack s2;
    s2.top = -1;
    copy(&s1, &s2);
    display(&s2);
    printf("\n");
    display(&s1);

    return 0;
}
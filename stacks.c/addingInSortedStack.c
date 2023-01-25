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
int main()
{
    struct stack s1;
    s1.top = -1;
    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 5);
    sorted_add(&s1, 4);
    display(&s1);

    return 0;
}
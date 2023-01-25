#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct stack
{
    int s[100];
    int top;
};

//checking if the stack is full
bool isFull(struct stack *s1)
{
    if (s1->top == 99)
    {
        return true;
    }
    return false;
}

//pushing element in stack
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

//popping element from stack
int pop(struct stack *st)
{
    if (st->top == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    int popped = st->s[st->top];
    st->top--;
    return popped;
}

//displaying elements of stack
void display(struct stack *st)
{
    if (st->top == -1)
        return;

    int y = st->s[st->top];
    printf("%d ", y);
    pop(st);
    display(st);
    push(st, y);
}

//finding lowest element of stack
int peekLowest(struct stack *st)
{
    static int x = INT_MAX;
    if (st->top != -1)
    {
        if (st->s[st->top] < x)
            x = st->s[st->top];

        int y = pop(st);
        peekLowest(st);
        push(st, y);
    }
    return x;
}

//finding highest element of stack
int peekHighest(struct stack *st)
{
    static int y = INT_MIN;
    if (st->top != -1)
    {
        if (st->s[st->top] > y)
            y = st->s[st->top];

        int z = pop(st);
        peekHighest(st);
        push(st, z);
    }
    return y;
}

//finding size of stack
int size(struct stack *st)
{
    static int l = 0;
    if (st->top == -1)
        return 1;

    int popped = pop(st);
    l++;
    size(st);
    push(st, popped);

    return l;
}

//finding middle element of stack
int peekMid(struct stack *st, int len)
{
    static int found;
    static int count = 1;
    if (st->top != -1)
    {
        if (count == len / 2 + 1)
        {
            found = st->s[st->top];
        }
        int popped = pop(st);
        count++;
        peekMid(st, len);
        push(st, popped);
    }

    return found;
}

//main function
int main()
{
    struct stack st;
    st.top = -1;

    int choice = 1;
    while (choice == 1)
    {
        printf("Enter element to be inserted \n");
        int a;
        scanf("%d", &a);
        push(&st, a);
        printf("The number is pushed sucessfully\n");

        printf("Do you want to enter more elements ? 1/0\n");
        scanf("%d", &choice);
        if (choice == 0)
            break;
    }

    printf("The stack is :\n");
    display(&st);
    printf("\n");

    printf("1.Peek lowest element\n");
    printf("1.Peek highest element\n");
    printf("1.Peek middle element\n");

    int x = 1;
    int y = 1;

    int ans1, ans2, ans3, len;
    while (y)
    {
        printf("Enter a choice from 1-3");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            ans1 = peekLowest(&st);
            printf("Lowest element is : %d\n", ans1);
            break;

        case 2:
            ans2 = peekHighest(&st);
            printf("Highest element is : %d\n", ans2);
            break;

        case 3:
            len = size(&st);
            ans3 = peekMid(&st, len);
            printf("Middle element is :%d\n", ans3);

        default:
            break;
        }
        printf("Do you want to enter more elements ? 1/0\n");
        scanf("%d", &y);
        if (y == 0)
            break;
    }

    printf("The program is terminated !!\n");
    return 0;
}
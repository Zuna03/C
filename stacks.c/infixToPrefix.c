#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int top;
    int capacity;
    int *arr;
};

struct stack *create(int capacity)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));

    if (!st)
        return NULL;

    st->top = -1;
    st->capacity = capacity;

    st->arr = (int *)malloc(st->capacity * sizeof(int));

    return st;
}
int isEmpty(struct stack *st)
{
    return st->top == -1;
}
char peek(struct stack *st)
{
    return st->arr[st->top];
}
char pop(struct stack *st)
{
    if (!isEmpty(st))
        return st->arr[st->top--];
    return '0';
}
void push(struct stack *st, char op)
{
    st->arr[++st->top] = op;
}

//  to check if the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

//to check higher precedence
int precedence(char ch)
{
    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;

    else
        return -1;
}

// converting given infix expression to prefix expression.
void infixToPrefix(char *exp)
{
    int i, k;
    strrev(exp);

    // Create a st of capacity
    // equal to expression size
    struct stack *st = create(strlen(exp));
    if (!st) // See if st was created successfully
        return;

    for (i = 0, k = -1; exp[i]; ++i)
    {

        // If the scanned character is
        // an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an
        // ‘(‘, push it to the st.
        else if (exp[i] == ')')
            push(st, exp[i]);

        // If the scanned character is an ')',
        // pop and output from the st
        // until an '(' is encountered.
        else if (exp[i] == '(')
        {
            while (!isEmpty(st) && peek(st) != ')')
                exp[++k] = pop(st);
            if (!isEmpty(st) && peek(st) != ')')
                return; // invalid expression
            else
                pop(st);
        }
        else // an operator is encountered
        {
            while (!isEmpty(st) &&
                   precedence(exp[i]) <= precedence(peek(st)))
                exp[++k] = pop(st);
            push(st, exp[i]);
        }
    }

    // pop all the operators from the st
    while (!isEmpty(st))
        exp[++k] = pop(st);

    exp[++k] = '\0';
    strrev(exp);
    printf("%s", exp);
}

// Driver program to test above functions
int main()
{
    char exp[] = "a+(b*c-(d/e^f)*g)*h";
    infixToPrefix(exp);
    return 0;
}

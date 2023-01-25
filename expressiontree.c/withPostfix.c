#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct stack
{
    struct node *val;
    struct stack *next;
};

// func to check whether stack is empty or not
bool isEmpty(struct stack *st)
{
    if (st == NULL)
        return true;
    else
        return false;
}

// func to push element in stack
void push(struct stack **st, struct node *nw)
{
    struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    new->val = nw;
    new->next = *st;
    *st = new;
}

// func to pop element from stack
struct node *pop(struct stack **st)
{
    struct stack *temp1;
    struct node *popped;
    if (isEmpty(*st))
        return NULL;
    else
    {
        temp1 = *st;
        *st = (*st)->next;
        popped = temp1->val;
        free(temp1);
        return popped;
    }
}

// func to check if the character is operator or not
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

// func to build new node
struct node *makenode(char c)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = c;
    root->right = root->left = NULL;

    return root;
}

// func to make expression tree from postfix expression
struct node *makepostfix(char postfix[])
{
    struct stack *st = NULL;

    struct node *root;
    struct node *popped1;
    struct node *popped2;

    for (int i = 0; i < strlen(postfix); i++)
    {
        if (!isOperator(postfix[i]))
        {
            root = makenode(postfix[i]);
            push(&st, root);
        }
        else
        {
            root = makenode(postfix[i]);
            popped1 = pop(&st);
            popped2 = pop(&st);

            root->right = popped1;
            root->left = popped2;

            push(&st, root);
        }
    }
    root = pop(&st);
    return root;
}

// func to travserse the tree in postfix manner
void postfixTraversal(struct node *root)
{
    if (root == NULL)
        return;

    postfixTraversal(root->left);
    postfixTraversal(root->right);
    printf("%c ", root->data);
}

// main func
int main()
{
    char postfix[] = {'a', 'b', '+', 'c', 'd', 'e', '+', '*', '*'};

    struct node *ans = makepostfix(postfix);
    postfixTraversal(ans);

    return 0;
}
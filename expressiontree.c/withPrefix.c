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

// func to make expression tree from prefix expression
struct node *makeprefix(char prefix[])
{
    struct stack *st = NULL;

    struct node *root;
    struct node *popped1;
    struct node *popped2;

    for (int i = strlen(prefix); i >= 0; i--)
    {
        if (!isOperator(prefix[i]))
        {
            root = makenode(prefix[i]);
            push(&st, root);
        }
        else
        {
            root = makenode(prefix[i]);
            popped1 = pop(&st);
            popped2 = pop(&st);

            root->right = popped2;
            root->left = popped1;

            push(&st, root);
        }
    }
    root = pop(&st);
    return root;
}

// func to travserse the tree in prefix manner
void prefixTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    prefixTraversal(root->left);
    prefixTraversal(root->right);
}

// main func
int main()
{
    char prefix[] = {'-', '+', '7', '*', '4', '5', '+', '2', '0'};

    struct node *ans = makeprefix(prefix);
    prefixTraversal(ans);

    return 0;
}
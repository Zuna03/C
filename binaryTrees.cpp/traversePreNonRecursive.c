#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int data)
{

    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

struct stack
{
    struct node *val;
    struct stack *next;
};

bool isEmpty(struct stack *st)
{
    if (st == NULL)
        return true;
    else
        return false;
}

struct node *makeNode(int num)
{
    struct node *nw = (struct node *)malloc(sizeof(struct node));
    nw->data = num;
    nw->left = NULL;
    nw->right = NULL;

    return nw;
}
void push(struct stack **st, struct node *num)
{
    struct stack *nw = (struct stack *)malloc(sizeof(struct stack));
    nw->val = num;
    nw->next = *st;
    *st = nw;
}

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
void preorder_iterative(struct node *root)
{
    struct stack *st = NULL;
    struct node *temp = root;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        if (temp->right)
            push(&st, temp->right);
        if (temp->left)
            temp = temp->left;
        else
            temp = pop(&st);
    }
}
void inorder_iterative(struct node *root)
{
    struct stack *st = NULL;
    struct node *temp = root;
    while (!isEmpty(st) || temp != NULL)
    {
        if (temp != NULL)
        {
            push(&st, temp);
            temp = temp->left;
        }
        else
        {
            temp = pop(&st);
            printf("%d ", temp->data);
            temp = temp->right;
        }
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root = NULL;
    // root = insert(root, makeNode(50));
    // root = insert(root, makeNode(30));
    // root = insert(root, makeNode(20));
    // root = insert(root, makeNode(40));
    // root = insert(root, makeNode(70));
    // root = insert(root, makeNode(60));
    // root = insert(root, makeNode(50));
    // root = insert(root, makeNode(50));
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    preorder_iterative(root);

    return 0;
}
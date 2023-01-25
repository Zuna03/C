#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(struct node *root, int val)
{
    struct node *nw = (struct node *)malloc(sizeof(struct node));
    nw->data = val;
    nw->right = NULL;
    nw->left = NULL;

    return nw;
}
int countNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    else
        return countNodes(root->left) + countNodes(root->right) + 1;
}

bool checkFullyComplete(struct node *root)
{
    if (root == NULL)
        return true;
    else
    {
        int lnodes = countNodes(root->left);
        int rnodes = countNodes(root->right);

        if (lnodes == rnodes)
            return true;

        else
            return false;
    }
}
int main()
{
    struct node *root = createNode(root, 1);
    root->left = createNode(root, 2);
    root->right = createNode(root, 3);
    root->left->left = createNode(root, 4);
    root->left->right = createNode(root, 5);
    root->right->left = createNode(root, 6);
    // root->right->right = createNode(root, 7);

    // int ans = countNodes(root);
    // printf("%d", ans);
    if (checkFullyComplete(root))
        printf("yes");
    else
        printf("no");
    return 0;
}
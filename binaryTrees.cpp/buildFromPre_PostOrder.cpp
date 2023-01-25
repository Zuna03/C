#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *buildTree(int pre[], int post[], int start, int end, int *preorderIdx, int size)
{
    if (*preorderIdx >= size || start > end)
        return NULL;

    struct node *nw = (struct node *)malloc(sizeof(struct node));
    nw->data = pre[*preorderIdx];
    nw->left = NULL;
    nw->right = NULL;
    ++*preorderIdx;

    if (start == end)
        return nw;

    int i;
    for (i = start; i < end; i++)
    {
        if (pre[*preorderIdx] == post[i])
            break;
    }
    if (i <= end)
    {
        nw->left = buildTree(pre, post, start, i, preorderIdx, size);
        nw->right = buildTree(pre, post, i + 1, end - 1, preorderIdx, size);
    }

    return nw;
}

void inorderPrint(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    inorderPrint(root->left);

    inorderPrint(root->right);
}
int main()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);
    int preOrderIdx = 0;

    struct node *ans = buildTree(pre, post, 0, size - 1, &preOrderIdx, size);
    inorderPrint(ans);
    return 0;
}
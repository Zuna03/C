#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

int search(int start, int end, int target, int in[])
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}
struct node *buildTree(int start, int end, int pre[], int in[])
{
    static int idx = 0;
    if (start > end)
        return NULL;

   
    int curr = pre[idx];
    idx++;
    struct node *nw = (struct node *)malloc(sizeof(struct node));
    nw->data = curr;
    nw->left=NULL;
    nw->right=NULL;

    if (start == end)
        return nw;

    int pos = search(start, end, curr, in);

    nw->right = buildTree(pos + 1, end, pre, in);
    nw->left = buildTree(start, pos - 1, pre, in);
    return nw;
}

void inorderPrint(struct node *root)
{ 
    if (root == NULL)
        return;
    inorderPrint(root->left);
    printf("%d ", root->data);
    inorderPrint(root->right);
}

int main()
{
    int preorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    struct node *ans = buildTree(0, 4, preorder, inorder);
    inorderPrint(ans);

    return 0;
}
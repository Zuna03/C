
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct node *insert(struct node *node, int key)
{

    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct node *pre_post(int start, int end, int pre[], int in[])
{
    static int idx = 0;
    if (start > end)
        return NULL;

    int curr = pre[idx];
    idx++;
    struct node *nw = (struct node *)malloc(sizeof(struct node));
    nw->key = curr;
    nw->left = NULL;
    nw->right = NULL;

    if (start == end)
        return nw;

    int pos = search(start, end, curr, in);

    nw->right = pre_post(pos + 1, end, pre, in);
    nw->left = pre_post(start, pos - 1, pre, in);
    return nw;
}
// Driver Code
int main()
{

    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    inorder(root);

    return 0;
}

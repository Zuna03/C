
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *nwNode(int item)
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

    // if (node == NULL)
    //     return nwNode(key);

    // if (key < node->key)
    //     node->left = insert(node->left, key);
    // else if (key > node->key)
    //     node->right = insert(node->right, key);

    // return node;
    struct node *nw, *parent, *ptr;
    nw = nwNode(key);
    if (node == NULL)
        node = nw;
    else
    {
        ptr = node;
        parent = NULL;
        while (ptr != NULL)
        {
            parent = ptr;
            if (key < ptr->key)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    if (key < parent->key)
        parent->left = nw;
    else
        parent->right = nw;
    return node;
}

bool checkBST(struct node *root, struct node *min, struct node *max)
{
    if (root == NULL)
        return true;

    if (max != NULL && root->key >= max->key)
        return false;

    if (min != NULL && root->key <= min->key)
        return false;

    bool leftValid = checkBST(root->left, min, root);
    bool rightValid = checkBST(root->right, root, max);

    return leftValid and rightValid;
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
    if (checkBST(root, NULL, NULL))
        printf("Valid");
    else
        printf("Invalid");

    return 0;
}

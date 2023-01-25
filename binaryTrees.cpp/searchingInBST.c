#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    // if (node == NULL)
    //     return newNode(key);

    // if (key < node->key)
    //     node->left = insert(node->left, key);
    // else if (key > node->key)
    //     node->right = insert(node->right, key);

    // return node;
    struct node *new, *parent, *ptr;
    new = newNode(key);
    if (node == NULL)
        node = new;
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
        parent->left = new;
    else
        parent->right = new;
    return node;
}

bool search(struct node *root, int val)
{
    struct node *temp;
    if (root == NULL)
        return false;
    else
    {
        temp = root;
        while (temp && temp->key != val)
        {
            if (temp->key == val)
                return true;
            else
            {
                if (temp->key > val)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
        }
        if (!temp)
            return false;
    }
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
    if (search(root, 70))
        printf("yes");
    else
        printf("no");

    return 0;
}

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
        printf("%d  ", root->key);
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

int search(struct node *root, int val)
{
    struct node *temp;
    if (root == NULL)
        return -1;
    else
    {
        temp = root;
        while (temp)
        {
            if (temp->key == val)
            {
                if (temp->left != NULL && temp->right != NULL)
                    return 2;
                else if (temp->left == NULL && temp->right || temp->right == NULL && temp->left)
                    return 1;
                else
                    return 0;
            }
            else
            {
                if (temp->key > val)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
        }
        if (!temp)
            return -1;
    }
}

struct node *findMin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *findNode(struct node *root, int val)
{
    struct node *temp;
    if (root == NULL)
        return NULL;
    else
    {
        temp = root;
        while (temp)
        {
            if (temp->key == val)
            {
                return temp;
            }
            else
            {
                if (temp->key > val)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
        }
        if (!temp)
            return NULL;
    }
}
void delete (struct node *root, int val)
{
    struct node *parent;
    struct node *ptr;
    ptr = root;
    parent = NULL;

    if (root == NULL)
        return;

    else if (ptr->key == val)
        root = NULL;

    else
    {
        int findDegree = search(root, val);
        if (findDegree == 0)
        {
            while (ptr->key != val)
            {
                parent = ptr;
                if (ptr->key > val)
                    ptr = ptr->left;
                else
                    ptr = ptr->right;
            }
            if (parent->key > val)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else if (findDegree == 1)
        {
            while (ptr->key != val)
            {
                parent = ptr;
                if (ptr->key > val)
                    ptr = ptr->left;
                else
                    ptr = ptr->right;
            }
            struct node *t;
            if (ptr->left != NULL)
                t = ptr->left;
            else
                t = ptr->right;
            if (parent->key > val)
                parent->left = t;
            else
                parent->right = t;
            free(ptr);
        }
        else
        {
            struct node *nodeFound = findNode(root, val);
            struct node *min = findMin(nodeFound->right);

            if (search(root, min->key) == 0)
            {
                ptr = root;

                while (ptr->key != min->key)
                {
                    parent = ptr;
                    if (ptr->key > min->key)
                        ptr = ptr->left;
                    else
                        ptr = ptr->right;
                }
                if (parent->key > min->key)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else
            {
                ptr = root;
                while (ptr->key != min->key)
                {
                    parent = ptr;
                    if (ptr->key > min->key)
                        ptr = ptr->left;
                    else
                        ptr = ptr->right;
                }
                struct node *t;
                if (ptr->left != NULL)
                    t = ptr->left;
                else
                    t = ptr->right;
                if (parent->key > min->key)
                    parent->left = t;
                else
                    parent->right = t;
                free(ptr);
            }
            int temp = nodeFound->key;
            nodeFound->key = min->key;
            min->key = temp;
        }
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
    inorder(root);
    printf("\n");
    delete (root, 30);
    printf("\n");
    inorder(root);

    // struct node *ans = findNode(root, 70);
    // printf("%d ", ans->left->key);

    return 0;
}

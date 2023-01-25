#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

bool searchNode(struct node *root, int target)
{

    if (root == NULL)
        return false;
    if (root->data == target)
        return true;
    searchNode(root->left, target);
    searchNode(root->right, target);
}

void addLeft(struct node *root, int val, int target)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->right = NULL;
    newNode->left = NULL;
    bool found = false;
    if (root == NULL)
        root->left = newNode;
    else
    {
        if (root == NULL)
            return;
        if (root->data == target)
            found = true;
        if (found == true)
            root->left = newNode;
        addLeft(root->left, val, target);
        addLeft(root->right, val, target);

        // if (searchNode(root, target))
        // {
        //     struct node *temp = root;
        //     while (temp->left != NULL)
        //     {
        //         temp = temp->left;
        //     }
        //     temp->left = newNode;
        // }
        // else
        // {
        //     printf("Node not present\n");
        //     return;
        // }
    }
}

void addRight(struct node *root, int val, int target)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->right = NULL;
    newNode->left = NULL;
    bool found = false;
    if (root == NULL)
        root->right = newNode;
    else
    {
        if (root == NULL)
            return;
        if (root->data == target)
            found = true;
        if (found == true)
            root->right = newNode;
        addRight(root->left, val, target);
        addRight(root->right, val, target);

        // if (searchNode(root, target))
        // {
        //     struct node *temp = root;
        //     while (temp->right != NULL)
        //     {
        //         temp = temp->right;
        //     }
        //     temp->right = newNode;
        // }
        // else
        // {
        //     printf("Node not present\n");
        //     return;
        // }
    }
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int val;
    struct node *root = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of root\n");
    scanf("%d", &val);
    root->data = val;
    root->right = NULL;
    root->left = NULL;

    printf("1) Add a node as left child of a node\n");
    printf("2) Add a node as right child of a node\n");
    printf("3) Print the inorder tree\n");
    printf("4) Print the preorder tree\n");
    printf("5) Print the postorder tree\n");

    int choice, value, target;
    int x = 1;

    while (x)
    {
        printf("Enter a choice from 1-5\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value of the node\n");
            scanf("%d", &value);
            printf("Enter value of the node whose left child will be added\n");
            scanf("%d", &target);
            addLeft(root, value, target);
            break;

        case 2:
            printf("Enter value of the node\n");
            scanf("%d", &value);
            printf("Enter value of the node whose right child will be added\n");
            scanf("%d", &target);
            addRight(root, value, target);
            break;

        case 3:
            printf("The tree is: \n");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("The tree is: \n");
            preorder(root);
            printf("\n");
            break;

        case 5:
            printf("The tree is: \n");
            postorder(root);
            printf("\n");
            break;

        default:
            break;
        }

        printf("Do you want to continue? 1/0 ");
        scanf("%d", &x);

        if (x == 0)
            break;
    }

    return 0;
}
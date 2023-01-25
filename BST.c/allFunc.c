#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

// Capacity of queue.
#define MaxQSize 500

// Structure for BST's node.
struct node
{
    int key;
    struct node *left, *right;
};

// Util function for inseting a new node if the BST is empty.
struct node *newNode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new element in the BST.
struct node *insert(struct node *node, int value)
{
    if (node == NULL)
        return newNode(value);

    if (value < node->key)
        node->left = insert(node->left, value);
    else if (value > node->key)
        node->right = insert(node->right, value);

    return node;
}

// Util function to check BST or not.
bool isBSTUtil(struct node *node, int min, int max)
{
    if (node == NULL)
        return true;
    if (node->key < min || node->key > max)
        return false;

    return isBSTUtil(node->left, min, node->key - 1) && isBSTUtil(node->right, node->key + 1, max);
}

// Function to check whether the BT is BST or not.
bool isBST(struct node *node)
{
    return isBSTUtil(node, INT_MIN, INT_MAX);
}

// Function to traverse BST in preorder.
void preorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->key);
    preorder(node->left);
    preorder(node->right);
}

// Function to traverse BST in postorder.
void postorder(struct node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->key);
}

// Function to traverse BST in inorder.
void inorder(struct node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}

// Function to check whether a node is present or not.
bool search(struct node *node, int val)
{
    if (node == NULL)
        return false;
    struct node *temp = node;

    while (temp && temp->key != val)
    {
        if (temp->key == val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (!temp)
        return false;
    return true;
}

// Util function to for deleting node in BST.
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Delete a node in the BST.
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// stack ADT.
struct stack
{
    struct node *data;
    struct stack *next;
};

// Adt function for stack to push.
void pushStack(struct stack **st, struct node *val)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = val;
    temp->next = *st;
    *st = temp;
}

// Adt function for stack to check whether stack is empty or not.
int isEmptyS(struct stack *st)
{
    return !st;
}

// Adt function for stack to pop.
struct node *popStack(struct stack **st)
{
    if (isEmptyS(*st))
    {
        printf("Empty stack\n");
        return NULL;
    }
    struct stack *temp = *st;
    *st = (*st)->next;
    struct node *popped = temp->data;
    free(temp);
    return popped;
}

// Function to print in preorder format with iteration.
void preorderItr(struct node *root)

{
    if (!root)
        return;
    struct stack *st = NULL;
    pushStack(&st, root);

    while (!isEmptyS(st))
    {
        root = popStack(&st);
        printf("%d ", root->key);
        if (root->right)
            pushStack(&st, root->right);
        if (root->left)
            pushStack(&st, root->left);
    }
}

// Adt function for queue to create a queue.
struct node **createQueue(int *front, int *rear)
{
    struct node **queue = (struct node **)malloc(sizeof(struct node *) * MaxQSize);

    *front = *rear = 0;

    return queue;
}

// Adt function for queue to enqueue.
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

// Adt function for queue to dequeue.
struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

// Function to traverse in level order.
void levelOrder(struct node *root)
{
    int rear, front;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp_node = root;

    while (temp_node)
    {
        printf("%d ", temp_node->key);

        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        temp_node = deQueue(queue, &front);
    }
}

// Main Function.
int main()
{
    struct node *root = NULL;
    int item;

    printf("Enter the value :- ");
    scanf("%d", &item);

    root = insert(root, item);

    int check = 1;

    while (check)
    {
        int z;
        printf("\n========================================================\n");
        printf("1) Insert a node.\n");
        printf("2) Check BST.\n");
        printf("3) Traverse preorder.\n");
        printf("4) Traverse preorder without recursion.\n");
        printf("5) Traverse postorder.\n");
        printf("6) Traverse inorder.\n");
        printf("7) Traverse in level order.\n");
        printf("8) Search for a node.\n");
        printf("9) Delete a node.\n");
        printf("10) QUIT!!.\n");
        printf("\n========================================================\n");

        printf("Enter your choice :- ");
        scanf("%d", &z);

        struct node *temp = root;

        switch (z)
        {
        case 1:
            printf("Enter the value :- ");
            scanf("%d", &item);
            insert(root, item);
            break;
        case 2:
            if (isBST(root))
                printf("It is a BST.\n");
            else
                printf("It is not a BST.\n");
            break;
        case 3:
            printf("The tree in preorder :- ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("The tree in preorder :- ");
            preorderItr(root);
            printf("\n");
            break;
        case 5:
            printf("The tree in postorder :- ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("The tree in inorder :- ");
            inorder(root);
            printf("\n");
            break;
        case 7:
            printf("The tree in level order :- ");
            levelOrder(root);
            printf("\n");
            break;
        case 8:
            printf("Enter the value :- ");
            scanf("%d", &item);
            if (search(root, item))
                printf("Element found!!\n");
            else
                printf("Element not found!!\n");
            break;
        case 9:
            printf("Enter the value :- ");
            scanf("%d", &item);
            root = deleteNode(root, item);
            break;
        case 10:
            check = 0;
            printf("Program terminated!!\n");
            break;
        default:
            printf("Invalid Choice !!\n");
            break;
        }
    }

    printf("\n========================================================\n");

    printf("Program exited successfully!!\n");

    return 0;
}
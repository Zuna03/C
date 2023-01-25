#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
    bool isThreaded;
};

struct node *newNode(int val)
{
    struct node *nw = (struct node *)malloc(sizeof(struct node));
    nw->data = val;
    nw->left = NULL;
    nw->right = NULL;
    nw->isThreaded = false;

    return nw;
}

struct node *createTree(struct node *root, int val)
{
    struct node *nw = newNode(val);
    if (root == NULL)
        root = nw;
    else
    {
        if (val < root->data)
            root->left = createTree(root->left, val);
        else
            root->right = createTree(root->right, val);
    }
    return root;
}

struct node **createQueue(int *front, int *rear)
{
    struct node **queue = (struct node **)malloc(sizeof(struct node *));

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

struct node *topQueue(struct node **queue, int *front)
{
    return queue[*front];
}
void storeInQueue(struct node *root, struct node **queue, int *rear)
{
    if (root == NULL)
        return;
    if (root->left)
        storeInQueue(root->left, queue, rear);
    enQueue(queue, rear, root);
    if (root->right)
        storeInQueue(root->right, queue, rear);
}

void createThread(struct node *root, struct node **queue, int *front, int *rear)
{
    if (root == NULL)
        return;
    if (root->left)
        createThread(root->left, queue, front, rear);
    deQueue(queue, front);
    if (root->right)
        createThread(root->right, queue, front, rear);
    else
    {
        root->right = topQueue(queue, front);
        root->isThreaded = true;
    }
}

void createThreadedBT(struct node *root)
{
    int front, rear;
    struct node **queue = createQueue(&front, &rear);

    storeInQueue(root, queue, &rear);

    createThread(root, queue, &front, &rear);
}

struct node *leftMost(struct node *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
    }
    return root;
}
void inorder(struct node *root)
{
    struct node *temp = leftMost(root);
    while (temp)
    {
        printf("%d ", temp->data);
        if (temp->isThreaded)
            temp = temp->right;
        else
            temp = leftMost(temp->right);
    }
}

int main()
{
    struct node *root = newNode(50);
    createTree(root, 90);
    createTree(root, 40);
    createTree(root, 190);
    createTree(root, 30);
    createTree(root, 10);
    // createTree(root, 110);

    createThreadedBT(root);
    inorder(root);

    return 0;
}
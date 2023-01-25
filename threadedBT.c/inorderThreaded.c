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

struct node *newnode(int val)
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
    struct node *nw = newnode(val);
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
void enqueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

// Adt function for queue to dequeue.
struct node *dequeue(struct node **queue, int *front)
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
    enqueue(queue, rear, root);
    if (root->right)
        storeInQueue(root->right, queue, rear);
}

void createThread(struct node *root, struct node **queue, int *front, int *rear)
{
    if (root == NULL)
        return;
    if (root->left)
        createThread(root->left, queue, front, rear);
    dequeue(queue, front);
    if (root->right)
        createThread(root->right, queue, front, rear);
    else
    {
        root->right = topQueue(queue, front);
        root->isThreaded = true;
    }
}

void creatwThreadedBT(struct node *root)
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
    int val;
    printf("Enter the vale of the root node\n");
    scanf("%d", &val);
    struct node *root = newnode(val);

    printf("1) Add node in a binary tree\n");
    printf("2) Print inorder\n");

    int choice, value;
    int check = 1;
    while (check)
    {
        printf("Enter a choice 1/2 : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter the value you want to add : ");
            scanf("%d", &value);
            printf("\n");
            createTree(root, value);
            break;

        case 2:
            printf("The inorder of the tree is : ");
            creatwThreadedBT(root);
            inorder(root);
            printf("\n");
            break;

        default:
            break;
        }

        printf("Do you want to continue 1/0 : ");
        scanf("%d", &check);
        printf("\n");

        if (check == 0)
            break;
    }
    printf("The program has been terminated successfully !\n");

    return 0;
}
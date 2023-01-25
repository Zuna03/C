#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int key;
    struct node *left, *right;
};

// func to make new node
struct node *newnode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// func for inorder traversal of tree
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

// func to iunsert new element in tree
struct node *insert(struct node *root, int key)
{
    struct node *new, *parent, *ptr;
    new = newnode(key);
    if (root == NULL)
        root = new;
    else
    {
        ptr = root;
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
    return root;
}

// func to calculate height of tree
int calcHeight(struct node *root)
{
    if (root == NULL)
        return -1;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    if (lHeight > rHeight)
        return lHeight + 1;
    else
        return rHeight + 1;
}

// func to count nodes with degree 0
int count0Degree(struct node *root)
{
    static int count = 0;
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        count++;

    count0Degree(root->left);
    count0Degree(root->right);

    return count;
}

// func to count nodes with degree 1
int count1Degree(struct node *root)
{
    static int count = 0;
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right != NULL || root->right == NULL && root->left != NULL)
        count++;

    count1Degree(root->left);
    count1Degree(root->right);

    return count;
}

// func to count nodes with degree 2
int count2Degree(struct node *root)
{
    static int count = 0;
    if (root == NULL)
        return 0;

    if (root->left != NULL && root->right != NULL)
        count++;

    count2Degree(root->left);
    count2Degree(root->right);

    return count;
}

// func to create queue
struct node **createQueue(int *front, int *rear)
{
    struct node **queue = (struct node **)malloc(sizeof(struct node *));

    *front = *rear = 0;
    return queue;
}

// func to insert elements in queue
void enqueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

// func to pop elements from queue
struct node *dequeue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

// func to check if queue is empty
bool isQueueEmpty(int *front, int *rear)
{
    return (*rear == *front);
}

// func to check whether tree is complete BT or not
bool isCompleteBT(struct node *root)
{

    if (root == NULL)
        return true;

    int rear, front;
    struct node **queue = createQueue(&front, &rear);

    bool flag = false;

    // Do level order traversal using queue.
    enqueue(queue, &rear, root);
    while (!isQueueEmpty(&front, &rear))
    {
        struct node *temp = dequeue(queue, &front);

        if (temp->left)
        {
            if (flag == true)
                return false;

            enqueue(queue, &rear, temp->left);
        }
        else
            flag = true;

        if (temp->right)
        {

            if (flag == true)
                return false;

            enqueue(queue, &rear, temp->right); // enqueue Right Child
        }
        else
            flag = true;
    }

    return true;
}

int right_subtree(struct node *pt)
{
    static int count2 = 0;
    //  static int count2 = 0;
    if (pt != NULL)
    {
        count2++;
        right_subtree(pt->left);
        right_subtree(pt->right);
    }

    return count2;
}

int left_subtree(struct node *ptr)
{
    static int count1 = 0;
    //   static int count2 = 0;
    if (ptr != NULL)
    {
        count1++;
        left_subtree(ptr->left);
        left_subtree(ptr->right);
    }

    return count1;
}

void check(struct node *root)
{
    int ltree_elements;
    int rtree_elements;

    if (root == NULL || root->left == NULL || root->right == NULL)
    {
        return;
    }
    else
    {
        ltree_elements = left_subtree(root->left);
        rtree_elements = right_subtree(root->right);
    }

    if (ltree_elements == rtree_elements)
    {
        printf("\n\nYes , it is a fully complete binary tree.");
    }
    else
    {
        printf("\n\nNo , not a fully complete binary tree.");
    }
}

int main()
{
    int val;
    printf("Enter the value of the root\n");
    scanf("%d", &val);
    struct node *root = newnode(val);

    printf("1. Insert a node in BST.\n");
    printf("2. Find height of tree.\n");
    printf("3. Check whether the tree is a fully complete binary tree or not.\n");
    printf("4. Count the number of nodes with degree 0, 1 and 2.\n");
    printf("5. Print Inorder of BST\n");

    int choice, height, deg0, deg1, deg2;
    int cont = 1;

    while (cont)
    {
        printf("Enter a choice from 1-5\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value of the node.\n");
            scanf("%d", &val);
            insert(root, val);
            break;

        case 2:
            height = calcHeight(root);
            printf("The height of the tree is : %d \n", height);
            break;

        case 3:
            if (isCompleteBT(root))
                printf("Yes the tree is Complete BT.\n");
            else
                printf("No the tree is not Complete BT.\n");
            break;

        case 4:
            deg0 = count0Degree(root);
            printf("The number of nodes with degree 0 : %d\n", deg0);
            deg1 = count1Degree(root);
            printf("The number of nodes with degree 1 : %d\n", deg1);
            deg2 = count2Degree(root);
            printf("The number of nodes with degree 2 : %d\n", deg2);
            break;

        case 5:
            printf("The inorder sequence of BST is :\n");
            inorder(root);
            break;

        default:
            break;
        }

        printf("Do you want to continue? 1/0\n");
        scanf("%d", &cont);

        if (cont == 0)
            break;
    }

    printf("The program is terminated !\n");

    return 0;
}

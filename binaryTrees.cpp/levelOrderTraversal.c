#include <stdio.h>
#include <stdlib.h>

// Capacity of queue.
#define MaxQSize 500

// Structure for BST's node.
struct node
{
    int key;
    struct node *left, *right;
};

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
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
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

    levelOrder(root);

    return 0;
}
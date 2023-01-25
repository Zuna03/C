#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct qnode
{
    int data;
    struct qnode *next;
};
struct queue
{
    struct qnode *f;
    struct qnode *r;
};

struct qnode *createNode(int n)
{
    struct qnode *new = (struct qnode *)malloc(sizeof(struct qnode));
    new->data = n;
    new->next = NULL;

    return new;
}

struct queue *createQueue()
{
    struct queue *new = (struct queue *)malloc(sizeof(struct queue));
    new->f = NULL;
    new->r = NULL;
}

bool isEmpty(struct queue *q)
{
    if (q->f == NULL && q->r == NULL)
        return true;
    else
        return false;
}

void insert(struct queue *q, int n)
{
    struct qnode *temp = createNode(n);

    if (isEmpty(q))
    {
        q->f = temp;
        q->r = temp;
        return;
    }
    else
    {
        q->r->next = temp;
        q->r = temp;
        return;
    }
}

int delete(struct queue *q)
{
    if (isEmpty(q))
        return -1;

    struct qnode *todelete = q->f;
    q->f = q->f->next;

    if (q->f == NULL)
        q->r = NULL;

    int deleted = todelete->data;
    free(todelete);

    return deleted;
}

void display(struct queue *q1)
{
    struct queue *q2 = createQueue();
    int t1, t2;
    while (!isEmpty(q1))
    {
        t1 = delete(q1);
        printf("%d ", t1);
        insert(q2, t1);
    }
    printf("\n");
    while (!isEmpty(q2))
    {
        t2 = delete(q2);
        insert(q1, t2);
    }
    printf("\n");
}

int main()
{
    struct queue *q = createQueue();

    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Display the queue\n");

    int x;
    int choice;
    int ele;
    int deleted;
    do
    {
        printf("Enter a choice from 1-3\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element you want to insert in queue : \n");
            scanf("%d", &ele);
            insert(q, ele);
            printf("%d is inserted successfully\n", ele);
            break;

        case 2:
            deleted = delete(q);
            printf("%d is deleted successfully\n", deleted);
            break;

        case 3:
            printf("The current queue is\n");
            display(q);
            break;

        default:
            break;
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &x);

        if (x == 0)
        {
            break;
        }
    } while (x);
    printf("The program is terminated successfully.\n");

    return 0;
}
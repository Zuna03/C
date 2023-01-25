#include <stdio.h>
#include <stdbool.h>
#define max 100

struct queue
{
    int arr[max];
    int f, r;
};

//Function for checking if quque is empty(UNDERFLOW CONDITION)
bool isEmpty(struct queue *q)
{
    if (q->f == -1 && q->r == -1)
        return true;
    else
        return false;
}

//Function for checking if quque is full(OVERFLOW CONDITION)
bool isFull(struct queue *q)
{
    if (q->f == max - 1)
        return true;
    else
        return false;
}

//Function for inserting an element in queue
void insert(struct queue *q, int n)
{
    if (isFull(q))
        return;

    else if (isEmpty(q))
    {
        q->f++;
        q->r++;
        q->arr[q->r] = n;
    }
    else
    {
        q->r++;
        q->arr[q->r] = n;
    }
}

//Function for deleting an element in queue
int delete(struct queue *q)
{
    int t;
    if (isEmpty(q))
        return -1;
    else if (q->f == q->r)
    {
        t = q->arr[q->f];
        q->f = -1;
        q->r = -1;
    }
    else
    {
        t = q->arr[q->f];
        q->f++;
    }
    return t;
}

//Function for displaying queue
void display(struct queue *q1)
{
    struct queue q2;
    q2.f = -1;
    q2.r = -1;
    int t1, t2;
    while (!isEmpty(q1))
    {
        int t1 = delete(q1);
        printf("%d ", t1);
        insert(&q2, t1);
    }
    while (!isEmpty(&q2))
    {
        int t2 = delete(&q2);
        insert(q1, t2);
    }
    printf("\n");
}

//Function for reversing queue
void reverse(struct queue *q)
{

    if (isEmpty(q))
        return;
    else
    {
        int t = delete(q);
        reverse(q);
        insert(q, t);
    }
}

//Function for copying queue
void copy(struct queue *q1, struct queue *q2)
{

    if (q1->r == -1)
        return;
    int b = delete(q1);
    insert(q2, b);
    copy(q1, q2);
    insert(q1, b);
}

//main function
int main()
{
    struct queue q1;
    q1.f = -1;
    q1.r = -1;

    int t;
    display(&q1);

    struct queue q2;
    q2.f = -1;
    q2.r = -1;

    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Display the queue\n");
    printf("4. Reverse the queue\n");
    printf("5. Copy the queue\n");

    int x = 1;
    int choice;
    int ele;
    int deleted;
    do
    {
        printf("Enter a choice from 1-5\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element you want to insert in queue : \n");
            scanf("%d", &ele);
            insert(&q1, ele);
            printf("%d is inserted successfully\n", ele);
            break;

        case 2:
            deleted = delete(&q1);
            printf(" %d is deleted successfully\n", deleted);
            break;

        case 3:
            printf("The current queue is\n");
            display(&q1);
            break;

        case 4:
            reverse(&q1);
            printf("queue is reversed successfully\n");
            break;

        case 5:
            copy(&q1, &q2);
            printf("The copied queue is :\n");
            display(&q2);
            while (!isEmpty(&q2))
            {
                delete(&q2);
            }
            reverse(&q1);
            break;

        default:
            break;
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
    } while (choice);
    printf("The program is terminated successfully.\n");

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define max 100
struct queue
{
    int arr[max];
    int front;
    int rear;
};

bool isFull(struct queue *q)
{
    if (q->front == 0 && q->rear == max - 1 || q->rear + 1 == q->front)
        return true;
    else
        return false;
}

void enque(struct queue *q, int ele)
{
    if (isFull(q))
        return;
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = ele;
    }
    else if (q->rear == max - 1)
    {
        q->rear = 0;
        q->arr[q->rear] = ele;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = ele;
    }
}

bool isEmpty(struct queue *q)
{
    if (q->rear == -1 && q->front == -1)
        return true;
    else
        return false;
}

int dequeue(struct queue *q)
{
    int delete;
    if (isEmpty(q))
    {
        printf("Underflow\n");
        return -1;
    }
    else if (q->front == max - 1)
    {
        delete = q->arr[q->front];
        q->front = 0;
        return delete;
    }
    else if (q->front == q->rear)
    {
        delete = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
        return delete;
    }
    else
    {
        delete = q->arr[q->front];
        q->front++;
        return delete;
    }
}

int findMax(struct queue *q)
{
    struct queue q1;
    q1.front = -1;
    q1.rear = -1;
    int delete1;
    int delete2;

    int ans = INT_MIN;
    while (!isEmpty(q))
    {
        if (q->arr[q->front] > ans)
        {
            ans = q->arr[q->front];
        }
        else
        {
            delete1 = dequeue(q);
            enque(&q1, delete1);
        }
    }
    while (!isEmpty(&q1))
    {
        delete2 = dequeue(&q1);
        enque(q, delete2);
    }
    return ans;
}

void display(struct queue *q)
{
    int maxNum = findMax(q);
    int i = q->front;
    do
    {
        printf("%d ", q->arr[i]);
        i = (i) % maxNum;
        i++;
    } while (i != q->rear + 1);
}
int main()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;

    printf("1) Insert an element in queue\n");
    printf("2) Delete an element from queue\n");
    printf("3) Display elements of queue\n");

    int choice;
    int x = 1;
    int ele;
    int delete;

    while (x)
    {
        printf("Enter a choice from 1-3\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element you want to insert in queue\n");
            scanf("%d", &ele);
            enque(&q, ele);
            printf("%d is inserted successfully.\n", ele);
            break;

        case 2:
            delete = dequeue(&q);
            if (delete == -1)
                break;
            printf("The delete element is %d \n", delete);
            break;

        case 3:
            printf("The current queue is\n");
            display(&q);
            printf("\n");
            break;

        default:
            break;
        }
        printf("Do you want to continue ? 1/0  ");
        scanf("%d", &x);
        if (x == 0)
            break;
    }
    printf("The program is terminated successfully !!!\n");

    return 0;
}
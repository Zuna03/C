#include <stdio.h>
#include <stdbool.h>

#define max 100

struct queue
{
    int arr[max];
    int front, rear;
};

bool isEmpty(struct queue *q)
{
    if (q->front == -1 && q->rear == -1)
        return true;
    else
        return false;
}

bool isFull(struct queue *q)
{
    if (q->front == max - 1)
        return true;
    else
        return false;
}

void push(struct queue *q, int n)
{
    if (isFull(q))
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        if (q->front == -1 && q->rear == -1)
        {
            q->front++;
            q->rear++;
            q->arr[q->rear] = n;
        }
        else
        {
            q->rear++;
            q->arr[q->rear] = n;
        }
    }
}

int pop(struct queue *q)
{
    int popped;
    if (isEmpty(q))
    {
        printf("Underflow\n");
        return -1;
    }
    else if (q->front == max - 1 || q->rear == q->front)
    {
        popped = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        popped = q->arr[q->front];
        q->front++;
    }
    return popped;
}

void display(struct queue *q)
{
    struct queue *q2;
    q2->front = -1;
    q2->rear = -1;
    if (isEmpty(q))
        return;
    else
    {
        while (!isEmpty(q))
        {
            int t = pop(q);
            printf("%d ", t);
            push(q2, t);
        }
        while (!isEmpty(q2))
        {
            int t = pop(q2);
            push(q, t);
        }
    }

    printf("\n");
}

void reverse(struct queue *q)
{
    if (isEmpty(q))
        return;
    else
    {
        int popped = pop(q);
        reverse(q);
        push(q, popped);
    }
}

// void copy(struct queue*q1,struct queue* q2)
// {
//         while (!isEmpty(q1))
//         {
//             int popped=pop(q1);
//             push(q2,popped);
//         }
// }

void copy(struct queue *q, struct queue *q1)
{
    while (q->front != -1)
    {
        int t;
        t = pop(q);
        push(q1, t);
    }
}

int main()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;

    push(&q, 1);
    push(&q, 2);
    push(&q, 3);
    push(&q, 4);
    push(&q, 5);

    display(&q);
    // reverse(&q);
    struct queue q1;
    q1.front = -1;
    q1.rear = -1;

    copy(&q,&q1);
    display(&q1);

    return 0;
}
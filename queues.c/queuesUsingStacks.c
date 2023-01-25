#include <stdio.h>
#include <stdlib.h>
#define N 20 //defining the size of queue
int s[N], top = -1;

int pop() //function to remove an element from stack
{
    return s[top--];
}
void push(int x) //function to insert an element into stack
{
    if (top == N - 1)
        printf("Stack is Full");
    else
    {
        top++;
        s[top] = x;
    }
}
void enqueue(int x) //function to insert element in the queue using recursive stack call
{
    push(x);
}
void print() //function to print elements of a queue
{
    int i;
    for (i = 0; i <= top; i++)
        printf("%d  ", s[i]);
}

int dequeue() //function to dequeue element from a queue using recursive stack call
{
    int data, res;
    if (top == -1)
        printf("Queue is Empty");
    else if (top == 0)
        return pop();
    data = pop();
    res = dequeue();
    push(data);
    return res;
}
int main()
{
    int opt, data, t;

    printf("1) To Insert the Data in Queue\n");
    printf("2) To Delete the data from the Queue\n");
    printf("3) To show the Data in Queue \n");

    int x = 1;

    while (x)
    {
        printf("Enter Your Choice from 1-3:-\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter your data need to be inserted\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            t = dequeue();
            printf("dequeued element:%d\n", t);

            break;
        case 3:
            printf("The current queue is\n");
            print();
            printf("\n");
            break;

        default:
            printf("Incorrect Choice");
        }

        printf("Do you want to continue ? 1/0  ");
        scanf("%d", &x);
        if (x == 0)
            break;
    }
    printf("The program is terminated successfully !!!\n");
    return 0;
}
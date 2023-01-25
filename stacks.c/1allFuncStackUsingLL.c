#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int data;
    struct stack *next;
};

//pushing element in stack
void push(struct stack **top, int n)
{
    struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    new->data = n;
    new->next = *top;
    *top = new;
}

//checking whether stack is empty
bool isEmpty(struct stack **top)
{
    if (*top == NULL)
    {
        return true;
    }
    else
        return false;
}

//popping element from stack
int pop(struct stack **top, int *b)
{
    if (isEmpty(top) == true)
    {
        printf("The stack is empty\n");
        return -1;
    }

    struct stack *toDelete = (*top);
    (*top) = (*top)->next;
    *b = toDelete->data;
    free(toDelete);

    return *b;
}

//displaying stack
void display(struct stack *top)
{
    if (isEmpty(&top) == true)
    {
        printf("The stack is empty\n");
        return;
    }
    int b;
    int temp = pop(&top, &b);
    printf("%d ", temp);
    display(top);
    push(&top, temp);
}

int main()
{
    struct stack *st = NULL;

    int check = 1;
    int b;

    printf("1.Push an element into the stack.\n");
    printf("2.Pop an element from the stack.\n");
    printf("3.Display a stack.\n");

    while (check)
    {
        int ch, val;
        printf("Enter your choice (1-3) ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value need to be inserted :- \n");
            scanf("%d", &val);
            push(&st, val);
            printf("%d is pushed successfully.\n", val);
            break;
        case 2:
            pop(&st, &b);
            printf("The element was popped successfully.\n");
            break;
        case 3:
            printf("The current stack is :-\n");
            display(st);
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &check);

        if (check == 0)
        {
            break;
        }
    }
    printf("The program is terminated !!\n");
    return 0;
}

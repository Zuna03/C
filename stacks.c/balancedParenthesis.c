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
int pop(struct stack **top)
{
    if (isEmpty(top) == true)
    {
        printf("The stack is empty\n");
        return -1;
    }

    struct stack *toDelete = (*top);
    (*top) = (*top)->next;
    int b = toDelete->data;
    free(toDelete);

    return b;
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
    int temp = pop(&top);
    printf("%d ", temp);
    display(top);
    push(&top, temp);
}

// Returns 1 if character1 and character2 are matching left
// and right Brackets
bool isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

// Return 1 if expression has balanced Brackets
bool areBracketsBalanced(char exp[])
{

    // Declare an empty character stack
    struct stack *stack = NULL;

    for (int i = 0; exp[i]; i++)
    {
        // If the exp[i] is a starting bracket then push
        // it
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&stack, exp[i]);

        // If exp[i] is an ending bracket then pop from
        // stack and check if the popped bracket is a
        // matching pair*/
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {

            // If we see an ending bracket without a pair
            // then return false
            if (stack == NULL)
                return 0;

            // Pop the top element from stack, if it is not
            // a pair bracket of character then there is a
            // mismatch.
            else if (!isMatchingPair(pop(&stack), exp[i]))
                return 0;
        }
    }

    // If there is something left in expression then there
    // is a starting bracket without a closing
    // bracket
    if (stack == NULL)
        return 1; // balanced
    else
        return 0; // not balanced
}

// Driver code
int main()
{
    char exp[100] = "{()}[]";

    // Function call
    if (areBracketsBalanced(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}

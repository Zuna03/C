// #include <stdio.h>
// #include <string.h>

// struct stack
// {
//     int s[100];
//     int top;
// };

// void push(struct stack *s1, char n)
// {
//     if (s1->top == 99)
//         printf("Overflow\n");
//     else
//     {
//         s1->top++;
//         s1->s[s1->top] = n;
//     }
// }

// char pop(struct stack *s1)
// {
//     int b;
//     if (s1->top == -1)
//     {
//         printf("Underflow\n");
//         return ' ';
//     }
//     else
//     {
//         b = s1->s[s1->top];
//         s1->top--;
//         return b;
//     }
// }

// int postfix(char *p, int l)
// {
//     struct stack st;
//     st.top = -1;

//     for (int i = l-1; i >= 0; i--)
//     {
//         if (p[i] >= '0' && p[i] <= '9')
//             push(&st, p[i] - '0');
//         else
//         {
//             int y = pop(&st);
//             int x = pop(&st);

//             switch (p[i])
//             {
//             case '+':
//                 push(&st, x + y);
//                 break;

//             case '-':
//                 push(&st, x - y);
//                 break;

//             case '*':
//                 push(&st, x * y);
//                 break;

//             case '/':
//                 push(&st, x / y);
//                 break;

//             default:
//                 break;
//             }
//         }
//     }
//     return pop(&st);
// }

// int main()

// {
//     char p[] = "+9*26";
//     int l = strlen(p);
//     printf("prefix evaluation: %d", postfix(p, l));
//     return 0;
// }

#include <stdio.h>
#include <string.h>

struct stack_198
{
    int s[100];
    int top_198;
};

//pushing element to stack
void push_198(struct stack_198 *s1, char n)
{
    if (s1->top_198 == 99)
        printf("Overflow\n");
    else
    {
        s1->top_198++;
        s1->s[s1->top_198] = n;
    }
}

//popping element from stack
char pop_198(struct stack_198 *s1)
{
    int b;
    if (s1->top_198 == -1)
    {
        printf("Underflow\n");
        return ' ';
    }
    else
    {
        b = s1->s[s1->top_198];
        s1->top_198--;
        return b;
    }
}

//calculating prefix
int prefix_198(char *p, int l)
{
    struct stack_198 st;
    st.top_198 = -1;

    for (int i = l - 1; i >= 0; i--)
    {
        if (p[i] >= '0' && p[i] <= '9')
            push_198(&st, p[i] - '0');
        else
        {
            int y = pop_198(&st);
            int x = pop_198(&st);

            switch (p[i])
            {
            case '+':
                push_198(&st, x + y);
                break;

            case '-':
                push_198(&st, x - y);
                break;

            case '*':
                push_198(&st, x * y);
                break;

            case '/':
                push_198(&st, x / y);
                break;

            default:
                break;
            }
        }
    }
    return pop_198(&st);
}

//main func
int main()
{
    char p[] = "+9*26";
    int l = strlen(p);
    printf("Prefix evaluation: %d", prefix_198(p, l));
    return 0;
}
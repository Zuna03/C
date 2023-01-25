#include <stdio.h>

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

//calculating postfix
int postfix(char *p)
{
  struct stack_198 st;
  st.top_198 = -1;

  int i = 0;
  for (i = 0; p[i]; i++)
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

//main function
int main()
{
  char p[] = "231*+9-";
  printf("Postfix evaluation: %d", postfix(p));
  return 0;
}
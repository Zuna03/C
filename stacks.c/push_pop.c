#include <stdio.h>
#define max 100

int s[max];
int top=-1;

void push(int n)
{
    if(top==max-1)
    printf("Overflow\n");
    else
    {
        top++;
        s[top]=n;
    }
}

int* pop()
{
    int n;
    if(top==-1)
    printf("Underflow\n");
    else
    {
        n=s[top];
        top--;
        return &n;
    }
}

void print()
{
    for (int i = top; i >=0 ;i--)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
}
int main()
{
    push(1);
    push(2);
    pop();
    push(3);
    push(4);
    print();
  
  return 0;
}
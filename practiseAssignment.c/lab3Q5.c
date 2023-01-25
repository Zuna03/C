#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

int mAx(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int second_largest(int*a,int n,int k)
{
    int max=0;
    for (int i = 2; i < n; i++)
    {
        max=mAx(a[i-2],a[i-1]);
        max=mAx(max,a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        
    }
    
    
}
int main()
{
    int n;
    scanf("%d",&n);

    int* a=(int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

   // printf("%d",second_largest(a,n));
    
  
  return 0;
}
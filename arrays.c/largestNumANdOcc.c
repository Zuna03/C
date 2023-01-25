// WAP to find the largest number and counts the occurrence of the largest
// number in a dynamic array of n integers using a single loop.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Finds the largest number and it’s frequency.
void maxNumFreq(int *a, int *num, int *count, int n)
{
    *num = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (*num < a[i])
        {
            *num = a[i];
            *count = 1;
        }
        else if (*num == a[i])
        {
            *count = *count + 1;
        }
    }
}
// Main Function.
int main()
{
    printf("Enter size of the array ;- \n");
    int n, *a;
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    printf("Enter elements of the array \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int max_num, count;
    maxNumFreq(a, &max_num, &count, n);
    printf("Max num is :- %d and it's frequency is:- %d", max_num, count);
    return 0;
}

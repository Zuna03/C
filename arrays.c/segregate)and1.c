// You are given an array of 0 s and 1 s in random order. Segregate 0 s on left side
// and 1 s on right side of the array. Traverse array only once.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Segregates 0’s and 1’s.
void segregate(int n, int *a)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        if (a[start] == 1 && a[end] == 0)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }
        if (a[start] == 0 && start < end)
        {
            start++;
        }

        if (a[end] == 1 && start < end)
        {
            end--;
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

    segregate(n, a);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
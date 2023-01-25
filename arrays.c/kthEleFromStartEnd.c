// WAP to find out the k th smallest and k th largest element stored in a dynamic
// array of n integers

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Swaps two integers.
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Returns the position of the desired element in sorted array.
int partition(int l, int r, int *a)
{
    int x = a[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[r]);
    return i;
}
// Finds kth index element.
int kthElement(int l, int r, int k, int *a)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = partition(l, r, a);
        if (pos - l == k - 1)
            return a[pos];
        if (pos - l > k - 1)
            return kthElement(l, pos - 1, k, a);
        return kthElement(pos + 1, r, k - pos + l - 1, a);
    }
    return INT_MAX;
}
// Main Function.
int main()
{
    printf("Enter size of the array ;- \n");

    int n, k, *a;
    scanf("%d", &n);

    printf("Enter value of k ;- \n");
    scanf("%d", &k);

    a = (int *)malloc(n * sizeof(int));

    printf("Enter elements of the array \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Kth element from start is : %d\n", kthElement(0, n - 1, k, a));
    printf("Kth element from end is : %d\n", kthElement(0, n - 1, n - k + 1, a));
    return 0;
}
// WAP to swap all the elements in the 1st column with all the corresponding
// elements in the last column, and 2nd column with the second last column and
// 3rd with 3rd last etc. of a 2-D dynamic array. Display the matrix.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Swaps Columns.
void swapColumn(int n, int m, int **a)
{
    int start = 0, end = m - 1;
    while (start < end)
    {
        for (int i = 0; i < n; i++)
        {
            int temp = a[i][start];
            a[i][start] = a[i][end];
            a[i][end] = temp;
        }
        start++;
        end--;
    }
}
// Main Function.
int main()
{
    printf("Enter rows and columns of matrix ;- \n");
    int n, m, **a;
    scanf("%d%d", &n, &m);

    a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter elements of the matrix \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The output matrix is :- \n");

    swapColumn(n, m, a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
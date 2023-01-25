#include <stdio.h>
#include <stdlib.h>

void swAp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ascend_rows(int **a, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                if (a[k][i] < a[j][i])
                {
                    swAp(&a[k][i], &a[j][i]);
                }
            }
        }
    }

}

void descend_column(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i][k] > a[i][j])
                {
                    swAp(&a[i][k], &a[i][j]);
                }
            }
        }
    }

}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    int **a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    ascend_rows(a, m, n);
    descend_column(a, m, n);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
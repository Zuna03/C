#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int k = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                k++;
            }
        }
    }

    int b[k + 1][3];

    int x = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                x++;
                b[x][0] = i;
                b[x][1] = j;
                b[x][2] = a[i][j];
            }
        }
    }
    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = x;

    for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
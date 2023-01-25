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

    int m1, n1;
    scanf("%d%d", &m1, &n1);

    int b[m1][n1];
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    int i, j, x, y;
    i = j = x = y = 0;

    int c[m + m1][3];

    for (int p = 0; p < m + m1; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            c[p][q] = 0;
        }
    }

    while (i < m && x < m1)
    {
        if (a[i][0] == b[x][0])
        {
            if (a[i][1] == b[x][1])
            {
                c[i][0] = a[i][0];
                c[i][1] = a[i][1];
                c[i][2] = a[i][2] + b[i][2];
                i++;
                x++;
            }
            else if (a[i][1] < b[x][1])
            {
                c[i][0] = a[i][0];
                c[i][1] = a[i][1];
                c[i][2] = a[i][2];
                i++;
            }
            else
            {
                c[x][0] = b[x][0];
                c[x][1] = b[x][1];
                c[x][2] = b[x][2];
                x++;
            }
        }
        else if (a[i][0] < b[x][0])
        {
            c[i][0] = a[i][0];
            c[i][1] = a[i][1];
            c[i][2] = a[i][2];
            i++;
        }
        else
        {
            c[x][0] = b[x][0];
            c[x][1] = b[x][1];
            c[x][2] = b[x][2];
            x++;
        }
    }

    while (i < m)
    {
        c[i][0] = a[i][0];
        c[i][1] = a[i][1];
        c[i][2] = a[i][2];
        i++;
    }

    while (x < m1)
    {
        c[x][0] = b[x][0];
        c[x][1] = b[x][1];
        c[x][2] = b[x][2];
        x++;
    }

    for (int p = 0; p < m + m1; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            printf("%d ", c[p][q]);
        }
        printf("\n");
    }

    return 0;
}
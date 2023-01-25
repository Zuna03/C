#include <stdio.h>

// COMPARING

char compare(int x, int y)
{
    if (x < y)
        return '<';

    else if (x > y)
        return '>';

    else
        return '=';
}

// ADDING OF TWO SPARSH MATRICES

void add(int A[][3], int B[][3], int C[][3])
{
    int i = 1, j = 1, k = 1;
    int t1, t2;

    if (A[0][0] != B[0][0] && A[0][1] != B[0][1])
    {
        printf("\nADDition not possible.");
        return;
        ;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    t1 = A[0][2];
    t2 = B[0][2];

    while (i <= t1 && j <= t2)
    {
        switch (compare(A[i][0], B[j][0]))
        {
        case '=':

            switch (compare(A[i][1], B[j][1]))
            {
            case '=':

                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2] + B[j][2];

                k++;
                i++;
                j++;
                break;

            case '<':

                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2];

                k++;
                i++;
                break;

            case '>':

                C[k][0] = B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];

                k++;
                j++;
                break;
            }
            break;

        case '<':

            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];

            k++;
            i++;
            break;

        case '>':

            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];

            k++;
            j++;
            break;
        }
    }

    while (i <= t1)
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        k++;
        i++;
    }

    while (j <= t2)
    {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        k++;
        j++;
    }

    C[0][2] = k-2 ;

    printf("\nValue of k = %d", k);

    printf("\n\nPrint the sum of two Three - Tuppled matrices:\n");

    for (i = 0; i <= k-1 ; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", C[i][j]);
        }

        printf("\n");
    }

    return;
}

// MAIN

int main()
{
    int i, j, k, m, n;

    printf("\nEnter the value of m and n: ");
    scanf("%d%d", &m, &n);

    // MATRIX - 1

    int a[m][n];

    printf("\nEnter the elements in matrix a: \n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nPrint matrix a:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }

    // CONVERTING INTO THREE TUPLE FORMAT

    int A[10][3];

    A[0][0] = m;
    A[0][1] = n;

    k = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                k++;

                A[k][0] = i;
                A[k][1] = j;
                A[k][2] = a[i][j];
            }
        }

        A[0][2] = k;
    }

    // PRINTING THREE TUPLED MATRIX

    printf("\n\nPrint Tupled matrix:\n");

    for (i = 0; i < k + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", A[i][j]);
        }
        printf("\n");
    }

    // MATRIX - 2

    int b[m][n];

    printf("\n\n\nEnter the elements in matrix b:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nPrint matrix a:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %d ", b[i][j]);
        }
        printf("\n");
    }

    // CONVERTING INTO THREE TUPLE FORMAT

    int B[10][3];

    int l;

    B[0][0] = m;
    B[0][1] = n;

    l = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (b[i][j] != 0)
            {
                l++;

                B[l][0] = i;
                B[l][1] = j;
                B[l][2] = b[i][j];
            }
        }

        B[0][2] = l;
    }

    printf("\n\nPrint Tupled matrix:\n");

    for (i = 0; i < l + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", B[i][j]);
        }

        printf("\n");
    }

    // NOW WE WILL FIND SUM OF TWO THREE-TUPPLED MATRICES

    int C[15][3];

    add(A, B, C);

    return 0;
}
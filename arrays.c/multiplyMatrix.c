//Write a C program to multiply two matrix.
#include <stdio.h>

//program to multiply two matrix

void multiply(int row1, int column1, int row2, int column2, int arr1[row1][column1], int arr2[row2][column2])
{
    int product[row1][column2];

    if (column1 != row2) //exception handled
    {
        printf("Multiplication not possible \n");
    }
    else
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column2; j++)
            {
                product[i][j] = 0;
                for (int y = 0; y < column1; y++)
                {
                    product[i][j] += arr1[i][y] * arr2[y][j];
                }
            }
        }
    }

    printf("The product of two matrix is :- \n");

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    //taking input

    printf("Enter row of  first matrix \n");
    int row1;
    scanf("%d", &row1);
    printf("Enter column of  matrix \n");
    int column1;
    scanf("%d", &column1);

    int arr1[row1][column1];

    printf("Enter elements of first matrix \n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter row of  second matrix \n");
    int row2;
    scanf("%d", &row2);
    printf("Enter column of  second matrix \n");
    int column2;
    scanf("%d", &column2);

    int arr2[row2][column2];

    printf("Enter elements of second matrix \n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    multiply(row1, column1, row2, column2, arr1, arr2);
    return 0;
}
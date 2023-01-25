// Write a C Program to find sum and subtraction of two matrices
#include <stdio.h>

//program to find sum of two matrix
void sum(int row1, int column1, int row2, int column2, int arr1[row1][column1], int arr2[row2][column2])
{
    int arr3[row1][column1];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("Sum of elements of two matrices is :-\n");

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            printf("%d  ", arr3[i][j]);
        }
        printf("\n");
    }
}

//program to find difference of two matrix

void difference(int row1, int column1, int row2, int column2, int arr1[row1][column1], int arr2[row2][column2])
{
    int arr3[row1][column1];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            arr3[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    printf("\n");

    printf("Difference of elements of two matrices is :-\n");

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            printf("%d  ", arr3[i][j]);
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

    if (row1 != row2 || column1 != column2)
    {
        printf("Sum can't be found \n"); //exception handled
    }

    sum(row1, column1, row2, column2, arr1, arr2);

    printf("\n");

    difference(row1, column1, row2, column2, arr1, arr2);

    return 0;
}
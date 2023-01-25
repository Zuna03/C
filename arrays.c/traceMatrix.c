//Write a C program to find the trace of (sum of diagonal element) matrix
#include <stdio.h>

//program to find sum of diagonal elements of a matrix

void trace(int row, int column, int arr1[row][column])
{
    int sum_major = 0;
    int sum_minor = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == j)
            {
                sum_major += arr1[i][j];
            }
            if (j == row - 1 - i)
            {
                sum_minor += arr1[i][j];
            }
        }
    }

    printf("The sum of major diagonal elements is :- %d \n", sum_major);
    printf("The sum of minor diagonal elements is :- %d \n", sum_minor);
}
int main()
{
    //taking input

    printf("Enter row of  matrix \n");
    int row;
    scanf("%d", &row);
    printf("Enter column of  matrix \n");
    int column;
    scanf("%d", &column);

    int arr1[row][column];

    printf("Enter elements of  matrix \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    if (row != column)
    {
        printf("Sum can not be found \n"); //exception handled
    }

    trace(row, column, arr1);

    return 0;
}
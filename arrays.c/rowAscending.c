//Write a C program to arrange row elements in ascending order .
#include <stdio.h>

// program to arrange elements of a row in ascending order

void arranging(int row, int column, int arr1[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            for (int k = 0; k < column - j; k++)
            {
                if (arr1[i][k] > arr1[i][k + 1])
                {
                    int temp = arr1[i][k];
                    arr1[i][k] = arr1[i][k + 1];
                    arr1[i][k + 1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d  ", arr1[i][j]);
        }
        printf("\n");
    }
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

    arranging(row, column, arr1);
    return 0;
}
//Write a C program to arrange column elements in ascending order
#include <stdio.h>

// program to arrange elements of a column in ascending order

void arranging_198(int row_198, int column_198, int arr1_198[row_198][column_198])
{
    for (int j = 0; j < column_198; j++)
    {
        for (int i = 0; i < row_198; i++)
        {
            for (int k = 0; k < row_198 - i; k++)
            {
                if (arr1_198[k][j] > arr1_198[k + 1][j])
                {
                    int temp = arr1_198[k][j];
                    arr1_198[k][j] = arr1_198[k + 1][j];
                    arr1_198[k + 1][j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < row_198; i++)
    {
        for (int j = 0; j < column_198; j++)
        {
            printf("%d  ", arr1_198[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    //taking input

    printf("Enter row of  matrix \n");
    int row_198;
    scanf("%d", &row_198);
    printf("Enter column of  matrix \n");
    int column_198;
    scanf("%d", &column_198);

    int arr1_198[row_198][column_198];

    printf("Enter elements of  matrix \n");
    for (int i = 0; i < row_198; i++)
    {
        for (int j = 0; j < column_198; j++)
        {
            scanf("%d", &arr1_198[i][j]);
        }
    }

    arranging_198(row_198, column_198, arr1_198);

    return 0;
}
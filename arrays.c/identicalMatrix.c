//Write a C program to check two matrices are identical or not .
#include <stdio.h>

//program to find whether two matrix are identical or not

void identical_198(int row1_198, int column1_198, int row2_198, int column2_198, int arr1_198[row1_198][column1_198], int arr2_198[row2_198][column2_198])
{
    int flag = 0;

    if (row1_198 == row2_198 && column1_198 == column2_198) //exception handled
    {
        for (int i = 0; i < row1_198; i++)
        {
            for (int j = 0; j < column1_198; j++)
            {
                if (arr1_198[i][j] == arr2_198[i][j])
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }

        if (flag == 0)
        {
            printf("Matrices are identical \n");
        }
        else
        {
            printf("Matrices are not identical \n");
        }
    }
    else
    {
        printf("Matrices are not identical \n");
    }
}
int main()
{

    //taking input

    printf("Enter row of  first matrix \n");
    int row1_198;
    scanf("%d", &row1_198);
    printf("Enter column of  matrix \n");
    int column1_198;
    scanf("%d", &column1_198);

    int arr1_198[row1_198][column1_198];

    printf("Enter elements of first matrix \n");
    for (int i = 0; i < row1_198; i++)
    {
        for (int j = 0; j < column1_198; j++)
        {
            scanf("%d", &arr1_198[i][j]);
        }
    }

    printf("Enter row of  second matrix \n");
    int row2_198;
    scanf("%d", &row2_198);
    printf("Enter column of  second matrix \n");
    int column2_198;
    scanf("%d", &column2_198);

    int arr2_198[row2_198][column2_198];

    printf("Enter elements of second matrix \n");
    for (int i = 0; i < row2_198; i++)
    {
        for (int j = 0; j < column2_198; j++)
        {
            scanf("%d", &arr2_198[i][j]);
        }
    }

    identical_198(row1_198, column1_198, row2_198, column2_198, arr1_198, arr2_198);
    return 0;
}
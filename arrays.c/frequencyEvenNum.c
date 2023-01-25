//Write a C program to find the frequency of even numbers in matrix .

#include <stdio.h>

//program to fing frquency of even numbers in a given matrix

void frequency(int row_198, int column_198, int arr1_198[row_198][column_198])
{
    int count_198 = 0;

    for (int i = 0; i < row_198; i++)
    {
        for (int j = 0; j < column_198; j++)
        {
            if (arr1_198[i][j] % 2 == 0)
            {
                count_198++;
            }
        }
    }

    printf("Frequency of even numbers is :- %d", count_198);
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

    frequency(row_198, column_198, arr1_198);
    return 0;
}
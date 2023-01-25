// Write a program to replace every element in the dynamic array with the next
// greatest element present in the same array.

#include <stdio.h>
#include <stdlib.h>

void arrange(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                arr[i] = arr[j];
                break;
            }
        }
    }
}

int main()
{

    int n;
    printf("Enter the size of the array \n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    arrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
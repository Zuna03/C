//Write a C Program to merge two sorted array.
#include <stdio.h>

void merge_array(int arr1[], int arr2[], int l1, int l2)
{
    int i = 0, j = 0, k = 0;

    int l3 = l1 + l2;
    int arr3[l1 + l2];

    while (i < l1 && j < l2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else if (arr1[i] > arr2[j])
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
        else
        {
            arr3[k] = arr1[i];
            i++;
            k++;
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    // for rest of the elements left in one of the two arrays

    while (i < l1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < l2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    int size = sizeof(arr3);

    // printing merged array

    for (int x = 0; x < l3; x++)
    {
        printf("%d  ", arr3[x]);
    }
}
int main()
{
    printf("Enter size of first array :- \n");
    int l1;
    scanf("%d", &l1);

    int arr1[l1];
    printf("Enter elements of first array");

    for (int i = 0; i < l1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array :- \n");
    int l2;
    scanf("%d", &l2);

    int arr2[l2];
    printf("Enter elements of second array");

    for (int i = 0; i < l2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    merge_array(arr1, arr2, l1, l2);

    return 0;
}
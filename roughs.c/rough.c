#include <stdio.h>

#include <stdlib.h>

void display(int a[], int n);

void bubble_sort(int a[], int n);

void selection_sort(int a[], int n);

int main()

{

    int n, choice, i;

    char ch[20];

    printf("Enter no. of elements u want to sort : ");

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)

    {

        printf("Enter %d Element : ", i + 1);

        scanf("%d", &arr[i]);
    }

    printf("Please select any option Given Below for Sorting : \n");

    while (1)

    {

        printf("\n1. Bubble Sort\n2. Selection Sort\n3. Display Array.\n4. Exit the Program.\n");

        printf("\nEnter your Choice : ");

        scanf("%d", &choice);

        switch (choice)

        {

        case 1:

            bubble_sort(arr, n);

            break;

        case 2:

            selection_sort(arr, n);

            break;

        case 3:

            display(arr, n);

            break;

        case 5:

            return 0;

        default:

            printf("\nPlease Select only 1-4 option ----\n");
        }
    }

    return 0;
}

void display(int arr[], int n)

{

    for (int i = 0; i < n; i++)

    {

        printf(" %d ", arr[i]);
    }
}

//---------------------Bubble Sort Function-----------

void bubble_sort(int arr[], int n)

{

    int i, j, temp;

    for (i = 0; i < n; i++)

    {

        for (j = 0; j < n - i - 1; j++)

        {

            if (arr[j] > arr[j + 1])

            {

                temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }
        }
    }

    printf("After Bubble sort Elements are : ");

    display(arr, n);
}

//------------------Selection Sort Function---------

void selection_sort(int arr[], int n)

{

    int i, j, temp;

    for (i = 0; i < n - 1; i++)

    {

        for (j = i + 1; j < n; j++)

        {

            if (arr[i] > arr[j])

            {

                temp = arr[i];

                arr[i] = arr[j];

                arr[j] = temp;
            }
        }
    }

    printf("After Selection sort Elements are : ");

    display(arr, n);
}
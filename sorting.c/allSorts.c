#include <stdio.h>

int *insertion_sort_198(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int j = i - 1;
        while (a[j] > current && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }

    return a;
}

int *bubble_sort_198(int a[], int n)
{
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {

            if (a[i + 1] < a[i])
            {
                int temp;
                temp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = temp;
            }
        }
        counter++;
    }
    return a;
}

int *selection_sort_198(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    return arr;
}

void merge_198(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void merge_sort_198(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort_198(arr, l, mid);
        merge_sort_198(arr, mid + 1, r);

        merge_198(arr, l, mid, r);
    }
}

void swap_198(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap_198(arr, i, j);
        }
    }
    swap_198(arr, i + 1, r);
    return i + 1;
}
void quick_sort_198(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);

        quick_sort_198(arr, l, pi - 1);
        quick_sort_198(arr, pi + 1, r);
    }
}

void printArray_198(int arr[], int size_198)
{
    for (int i = 0; i < size_198; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size_198;
    printf("Enter size of the array\n");
    scanf("%d", &size_198);
    int arr[size_198];

    printf("Enter elements of array\n");
    for (int i = 0; i < size_198; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    printf("Array before sort is : ");
    printArray_198(arr, size_198);

    printf("1) Insertion Sort\n");
    printf("2) Bubble Sort\n");
    printf("3) Selection Sort\n");
    printf("4) merge_198 Sort\n");
    printf("5) Quick Sort\n");

    int choice, value;
    int *ans;
    int check = 1;
    while (check)
    {
        printf("Enter a choice 1-5 : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            ans = insertion_sort_198(arr, size_198);
            printf("Array after insertion sort is : ");
            printArray_198(ans, size_198);
            break;

        case 2:
            ans = bubble_sort_198(arr, size_198);
            printf("Array after bubble sort is : ");
            printArray_198(ans, size_198);
            break;

        case 3:
            ans = selection_sort_198(arr, size_198);
            printf("Array after selection sort is : ");
            printArray_198(ans, size_198);
            break;

        case 4:
            merge_sort_198(arr, 0, size_198 - 1);
            printf("Array after merge_198 sort is : ");
            printArray_198(arr, size_198);
            break;

        case 5:
            quick_sort_198(arr, 0, size_198 - 1);
            printf("Array after quick sort is : ");
            printArray_198(arr, size_198);
            break;

        default:
            break;
        }

        printf("Do you want to continue 1/0 : ");
        scanf("%d", &check);
        printf("\n");

        if (check == 0)
            break;
    }
    printf("The program has been terminated successfully !\n");

    return 0;
}

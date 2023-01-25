// //Given an unsorted dynamic array arr and two numbers x and y, find the
// minimum distance between x and y in arr. The array might also contain
// duplicates. You may assume that both x and y are different and present in arr.//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int Min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int minDis(int arr[], int n, int x, int y)
{
    int posX = -1;
    int posY = -1;
    int dis = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            posX = i;
        }
        if (arr[i] == y)
        {

            posY = i;
        }
        if (posX != -1 && posY != -1)
        {
            dis = Min(dis, abs(posX - posY));
        }
    }
    return dis;
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

    int x;
    int y;
    printf("Enter the two numbers \n");
    scanf("%d %d", &x, &y);

    printf("Min distance between two num is  %d\n", minDis(arr, n, x, y));

    return 0;
}

#include <stdio.h>

int n, m;
void createAdj(int arr[][2], int adj[][n + 1])
{
    int x, y;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        x = arr[i][0];
        y = arr[i][1];

        adj[x][y] = 1;
        adj[y][x] = 1;
    }
}

void printAdjMatrix(int Adj[][n + 1])
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    n = 5; //highest val in arr

    int arr[][2] = {{1, 2}, {2, 3}, {4, 5}, {1, 5}};
    m = sizeof(arr) / sizeof(arr[0]);
    // m=4;

    int adj[n + 1][n + 1];

    createAdj(arr, adj);
    printAdjMatrix(adj);

    return 0;
}
#include <stdio.h>

void towerOfHanoi_198(int n, char src, char dest, char help)
{
    if (n == 0)
        return;

    towerOfHanoi_198(n - 1, src, help, dest);
    printf("move from %c to %c\n", src, dest);
    towerOfHanoi_198(n - 1, help, dest, src);
}
int main()
{

    towerOfHanoi_198(3, 'A', 'C', 'B');
    return 0;
}
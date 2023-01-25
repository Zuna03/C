//WAP to arrange the elements of a dynamic array such that all even numbers
// are followed by all odd numbers.//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Swap two int.
void Swap_198(int *xp_198, int *yp_198)
{
    int temp_198 = *xp_198;
    *xp_198 = *yp_198;
    *yp_198 = temp_198;
}
// Segregates odd and even.
void oddAfterEven_198(int *a_198, int n_198)
{
    int start_198 = 0, end_198 = n_198 - 1;
    while (start_198 < end_198)
    {
        while (a_198[start_198] % 2 == 0 && start_198 < end_198)
            start_198++;
        while (a_198[end_198] % 2 == 1 && start_198 < end_198)
            end_198--;

        // if (a_198[start_198] % 2 != 0 && a_198[end_198] % 2 == 0)
        if (start_198 < end_198)
        {
            Swap_198(&a_198[start_198], &a_198[end_198]);
            start_198++;
            end_198--;
        }
    }
}
// Main Function.
int main()
{
    printf("Enter size of the array ;- \n");
    int *a_198, n_198;
    scanf("%d", &n_198);
    a_198 = (int *)malloc(n_198 * sizeof(int));
    
    printf("Enter elements of the array \n");
    for (int i = 0; i < n_198; i++)
    {
        scanf("%d", &a_198[i]);
    }

    oddAfterEven_198(a_198, n_198);

    printf("The desired array is:- \n");
    for (int i = 0; i < n_198; i++)
    {
        printf("%d ", a_198[i]);
    }
    return 0;
}
// #include <stdio.h>
// #include <stdbool.h>
// #define size 10

// int hash_func(int val)
// {
//     return val % size;
// }

// int probe(int arr[size], int val)
// {
//     int ans = hash_func(val);
//     int i = 0;

//     while (arr[ans + i] != -1)
//     {
//         i++;
//     }

//     return (ans + i) % size;
// }

// void insert(int arr[size], int val)
// {
//     int ans = hash_func(val);
//     if (arr[ans] == -1)
//         arr[ans] = val;
//     else
//     {
//         // int idx = probe(arr, val);
//         // arr[idx] = val;
//         int i;
//         bool found = false;
//         for (i = ans + 1; i < size; i++)
//         {
//             if (arr[i] == -1)
//             {
//                 arr[i] = val;
//                 found = true;
//                 break;
//             }
//         }
//         if (found == false)
//         {
//             i = 0;
//             for (i = 0; i < ans; i++)
//             {
//                 if (arr[i] == -1)
//                 {
//                     arr[i] = val;
//                     found = true;
//                     break;
//                 }
//             }
//         }
//     }
// }

// bool search_next(int arr[size], int val, int idx)
// {
//     int i = idx;
//     bool found = false;
//     for (i = idx + 1; i < size; i++)
//     {
//         if (arr[i] == -1)
//             return false;
//         if (arr[i] == val)
//         {
//             found = true;
//             return true;
//         }
//     }
//     if (found == false)
//     {
//         i = 0;
//         for (i = 0; i < idx; i++)
//         {
//             if (arr[i] == val)
//             {
//                 found = true;
//                 return true;
//             }
//         }
//     }
//     return found;
// }

// // int search_next(int arr[size], int val, int idx)
// // {
// //     int i = idx;
// //     bool found = false;
// //     for (i = idx + 1; i < size; i++)
// //     {
// //         if (arr[i] == -1)
// //             return -1;
// //         if (arr[i] == val)
// //         {
// //             found = true;
// //             return i;
// //         }
// //     }
// //     if (found == false)
// //     {
// //         i = 0;
// //         for (i = 0; i < idx; i++)
// //         {
// //             if (arr[i] == val)
// //             {
// //                 found = true;
// //                 return i;
// //             }
// //         }
// //     }
// //     return found;
// // }

// int search(int arr[size], int val)
// {
//     int ans = hash_func(val);
//     if (arr[ans] == val)
//         return true;
//     else
//     {
//         // int i = 0;
//         // while (arr[(ans + i) % size] != val)
//         // {
//         //     i++;
//         // }
//         // return (ans + i) % size;

//         return search_next(arr, val, ans);
//     }
// }

// int delete (int arr[size], int val)
// {
//     int ans = hash_func(val);
//     if (arr[ans] == val)
//     {
//         arr[ans] = 0;
//         return arr[ans];
//     }
//     else
//     {
//         int i = ans;
//         bool found = false;
//         for (i = ans + 1; i < size; i++)
//         {
//             if (arr[i] == -1)
//                 return -1;
//             if (arr[i] == val)
//             {
//                 found = true;
//                 arr[i] = 0;
//                 return arr[i];
//             }
//         }
//         if (found == false)
//         {
//             i = 0;
//             for (i = 0; i < ans; i++)
//             {
//                 if (arr[i] == val)
//                 {
//                     found = true;
//                     arr[i] = 0;
//                     return arr[i];
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     int arr[size];
//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = -1;
//     }

//     insert(arr, 7);
//     insert(arr, 20);
//     insert(arr, 10);
//     insert(arr, 33);
//     insert(arr, 4);
//     insert(arr, 54);
//     insert(arr, 6);
//     insert(arr, 8);
//     insert(arr, 96);

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     insert(arr, 23);
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     delete (arr, 23);
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // int ans = search(arr, 23);
//     // printf("%d ", ans);

//     // if (search(arr, 23) == true)
//     //     printf("found");
//     // else
//     //     printf("not found");

//     return 0;
// }

#include <stdio.h>
#include <stdbool.h>
#define size 10

int hash_func_198(int val)
{
    return val % size;
}

void insert_198(int arr[size], int val)
{
    int ans = hash_func_198(val);
    if (arr[ans] == -1)
        arr[ans] = val;
    else
    {
        int i;
        bool found = false;
        for (i = ans + 1; i < size; i++)
        {
            if (arr[i] == -1)
            {
                arr[i] = val;
                found = true;
                break;
            }
        }
        if (found == false)
        {
            i = 0;
            for (i = 0; i < ans; i++)
            {
                if (arr[i] == -1)
                {
                    arr[i] = val;
                    found = true;
                    break;
                }
            }
        }
    }
}

bool search_next_198(int arr[size], int val, int idx)
{
    int i = idx;
    bool found = false;
    for (i = idx + 1; i < size; i++)
    {
        if (arr[i] == -1)
            return false;
        if (arr[i] == val)
        {
            found = true;
            return true;
        }
    }
    if (found == false)
    {
        i = 0;
        for (i = 0; i < idx; i++)
        {
            if (arr[i] == val)
            {
                found = true;
                return true;
            }
        }
    }
    return found;
}

int search_198(int arr[size], int val)
{
    int ans = hash_func_198(val);
    if (arr[ans] == val)
        return true;
    else
    {
        return search_next_198(arr, val, ans);
    }
}

int delete_198(int arr[size], int val)
{
    int ans = hash_func_198(val);
    if (arr[ans] == val)
    {
        arr[ans] = 0;
        return arr[ans];
    }
    else
    {
        int i = ans;
        bool found = false;
        for (i = ans + 1; i < size; i++)
        {
            if (arr[i] == -1)
                return -1;
            if (arr[i] == val)
            {
                found = true;
                arr[i] = 0;
                return arr[i];
            }
        }
        if (found == false)
        {
            i = 0;
            for (i = 0; i < ans; i++)
            {
                if (arr[i] == val)
                {
                    found = true;
                    arr[i] = 0;
                    return arr[i];
                }
            }
        }
    }
}

void print_198(int arr[size])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
    printf("\n");

    // insert_198(arr, 7);
    // insert_198(arr, 20);
    // insert_198(arr, 10);
    // insert_198(arr, 33);
    // insert_198(arr, 4);
    // insert_198(arr, 54);
    // insert_198(arr, 6);
    // insert_198(arr, 8);
    // insert_198(arr, 96);

    int choice, c = 1, ele, deleted;
    printf("1.Insert an element\n");
    printf("2.Delete an element\n");
    printf("3.Search an element\n");
    printf("4.Print elements\n\n");

    while (c)
    {
        printf("Enter choice from above(1-4)\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element need to be inserted\n");
            scanf("%d", &ele);
            insert_198(arr, ele);
            break;

        case 2:
            printf("Enter element need to be deleted\n");
            scanf("%d", &ele);
            delete_198(arr, ele);
            break;

        case 3:
            printf("Enter element need to be searched\n");
            scanf("%d", &ele);
            if (search_198(arr, ele) == true)
                printf("found\n");
            else
                printf("not found\n");
            break;

        case 4:
            print_198(arr);
            break;
        default:
            break;
        }
        printf("Do yo want to cont. (1/0)?\n");
        scanf("%d", &c);
        if (c == 0)
            break;
    }
    printf("Program terminated successfully\n");

    return 0;
}
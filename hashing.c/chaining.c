// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define size 10

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *makeNode(int val)
// {
//     struct node *newNode = malloc(sizeof(struct node));
//     newNode->data = val;
//     newNode->next = NULL;
// }

// int hash_func(int x)
// {
//     return (x % size);
// }

// void swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// void insert(struct node *chain[size], int value)
// {
//     struct node *newNode = makeNode(value);
//     int key = hash_func(value);

//     if (chain[key] == NULL)
//         chain[key] = newNode;

//     else
//     {

//         struct node *temp = chain[key];
//         while (temp->next)
//         {
//             temp = temp->next;
//         }

//         temp->next = newNode;
//         if (temp->data > newNode->data)
//             swap(&temp->data, &newNode->data);
//     }
// }

// void print(struct node *chain[size])
// {

//     for (int i = 0; i < size; i++)
//     {
//         struct node *temp = chain[i];
//         printf("chain[%d] -> ", i);
//         while (temp)
//         {
//             printf("%d -> ", temp->data);
//             temp = temp->next;
//         }
//         printf("NULL\n");
//     }
// }

// bool search(struct node *chain[size], int value)
// {
//     int ans = hash_func(value);
//     struct node *temp = chain[ans];
//     bool found = false;

//     while (temp)
//     {
//         if (temp->data == value)
//             return true;
//         temp = temp->next;
//     }
//     return found;
// }

// int delete (struct node *chain[size], int value)
// {
//     struct node *todeleted;
//     int deleted;

//     bool ans = search(chain, value);
//     if (ans == false)
//     {
//         printf("Value need to be deleted is not found\n");
//         return -1;
//     }
//     else
//     {
//         int idx = hash_func(value);
//         struct node *temp;
//         struct node *temp2;
//         if (chain[idx]->data == value)
//         {
//             todeleted = chain[idx];
//             chain[idx] = todeleted->next;
//             deleted = todeleted->data;
//             free(todeleted);
//         }
//         else
//         {
//             temp = chain[idx];
//             while (temp && temp->data != value)
//             {
//                 temp2 = temp;
//                 temp = temp->next;
//             }
//             todeleted = temp->next;
//             temp2->next = temp->next;
//             deleted = temp->data;
//             free(todeleted);
//         }

//         return deleted;
//     }
// }

// int main()
// {

//     struct node *chain[size];
//     for (int i = 0; i < size; i++)
//         chain[i] = NULL;

//     insert(chain, 7);
//     insert(chain, 20);
//     insert(chain, 0);
//     insert(chain, 33);
//     insert(chain, 10);
//     insert(chain, 4);
//     insert(chain, 23);
//     insert(chain, 5);

//     // print(chain);
//     delete (chain, 7);
//     print(chain);

//     // bool found = search(chain, 25);
//     // if (found)
//     //     printf("Found\n");
//     // else
//     //     printf("Not Found\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 10

struct node_198
{
    int data_198;
    struct node_198 *next_198;
};

struct node_198 *makenode_198(int val)
{
    struct node_198 *newnode_198 = malloc(sizeof(struct node_198));
    newnode_198->data_198 = val;
    newnode_198->next_198 = NULL;
}

int hasg_func_198(int x)
{
    return (x % size);
}

void swap_198(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert_198(struct node_198 *arr_198[size], int value)
{
    struct node_198 *newnode_198 = makenode_198(value);
    int key = hasg_func_198(value);

    if (arr_198[key] == NULL)
        arr_198[key] = newnode_198;

    else
    {

        struct node_198 *temp = arr_198[key];
        while (temp->next_198)
        {
            temp = temp->next_198;
        }

        temp->next_198 = newnode_198;
        if (temp->data_198 > newnode_198->data_198)
            swap_198(&temp->data_198, &newnode_198->data_198);
    }
}

void print_198(struct node_198 *arr_198[size])
{

    for (int i = 0; i < size; i++)
    {
        struct node_198 *temp = arr_198[i];
        printf("arr_198[%d] -> ", i);
        while (temp)
        {
            printf("%d -> ", temp->data_198);
            temp = temp->next_198;
        }
        printf("NULL\n");
    }
}

bool search_198(struct node_198 *arr_198[size], int value)
{
    int ans = hasg_func_198(value);
    struct node_198 *temp = arr_198[ans];
    bool found = false;

    while (temp)
    {
        if (temp->data_198 == value)
            return true;
        temp = temp->next_198;
    }
    return found;
}

int delete_198(struct node_198 *arr_198[size], int value)
{
    struct node_198 *todeleted_198;
    int deleted_198;

    bool ans = search_198(arr_198, value);
    if (ans == false)
    {
        printf("Value need to be deleted is not found\n");
        return -1;
    }
    else
    {
        int idx = hasg_func_198(value);
        struct node_198 *temp;
        struct node_198 *temp2;
        if (arr_198[idx]->data_198 == value)
        {
            todeleted_198 = arr_198[idx];
            arr_198[idx] = todeleted_198->next_198;
            deleted_198 = todeleted_198->data_198;
            free(todeleted_198);
        }
        else
        {
            temp = arr_198[idx];
            while (temp && temp->data_198 != value)
            {
                temp2 = temp;
                temp = temp->next_198;
            }
            todeleted_198 = temp->next_198;
            temp2->next_198 = temp->next_198;
            deleted_198 = temp->data_198;
            free(todeleted_198);
        }

        return deleted_198;
    }
}

int main()
{

    struct node_198 *arr_198[size];
    for (int i = 0; i < size; i++)
        arr_198[i] = NULL;

    // insert_198(arr_198, 7);
    // insert_198(arr_198, 20);
    // insert_198(arr_198, 0);
    // insert_198(arr_198, 33);
    // insert_198(arr_198, 10);
    // insert_198(arr_198, 4);
    // insert_198(arr_198, 23);
    // insert_198(arr_198, 5);

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
            insert_198(arr_198, ele);
            break;

        case 2:
            printf("Enter element need to be deleted\n");
            scanf("%d", &ele);
            delete_198(arr_198, ele);
            break;

        case 3:
            printf("Enter element need to be searched\n");
            scanf("%d", &ele);
            if (search_198(arr_198, ele) == true)
                printf("found\n");
            else
                printf("not found\n");
            break;

        case 4:
            print_198(arr_198);
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
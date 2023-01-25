// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void append_node_node(struct node **start, int n)
// {
//     struct node *new = (struct node *)malloc(sizeof(struct node));
//     new->data = n;
//     new->next = NULL;

//     struct node *temp;

//     if (*start == NULL)
//     {
//         *start = new;
//         return;
//     }
//     else
//     {
//         temp = *start;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = new;
//         new->next = NULL;
//     }
// }

// // 1) Program to  Print Current List :-

// void display(struct node **start)
// {

//     struct node *temp = *start;
//     while (temp != NULL)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
// }

// struct node* merge(struct node *s1, struct node *s2, struct node *head)
// {

//     while (s1 != NULL && s2 != NULL)
//     {

//         if (s1->data < s2->data)
//         {
//             append_node_node(&head, s1->data);
//             s1 = s1->next;
//         }
//         else if (s1->data > s2->data)
//         {
//             append_node_node(&head, s2->data);
//             s2 = s2->next;
//         }
//         else
//         {
//             append_node_node(&head, s2->data);
//             s1 = s1->next;
//             s2 = s2->next;
//         }
//     }

//     while (s1 != NULL)
//     {
//         append_node_node(&head, s1->data);
//         s1 = s1->next;
//     }

//     while (s2 != NULL)
//     {
//         append_node_node(&head, s2->data);
//         s2 = s2->next;
//     }

//    return head;
// }


// int main()
// {
//     struct node *s1 = NULL;
//     struct node *s2 = NULL;

//     append_node_node(&s1, 1);
//     append_node_node(&s1, 5);
//     append_node_node(&s1, 7);
//     append_node_node(&s1, 11);
//     // display(&s1);

//     printf("\n");

//     append_node_node(&s2, 2);
//     append_node_node(&s2, 4);
//     append_node_node(&s2, 8);
//     append_node_node(&s2, 13);
//     append_node_node(&s2, 17);

//     // display(&s2);

//     printf("\n");

//     struct node *head = NULL;
//     struct node* ans=merge(s1, s2, head);
//      display(&ans);

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_198
{
    int data;
    struct node_198 *next;
};

void create(struct node_198 **start, int n)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data = n;
    new_198->next = NULL;

    struct node_198 *temp_198;

    if ((*start) == NULL)
    {
        (*start) = new_198;
        return;
    }
    else
    {
        temp_198 = (*start);
        while (temp_198->next != NULL)
        {
            temp_198 = temp_198->next;
        }
        temp_198->next = new_198;
        new_198->next = NULL;
    }
}

void display_198(struct node_198 **start)
{
    struct node_198 *temp_198 = *start;
    while (temp_198 != NULL)
    {
        printf("%d ", temp_198->data);
        temp_198 = temp_198->next;
    }
    printf("\n");
}

struct node_198 *merge_198(struct node_198 *s1, struct node_198 *s2, struct node_198 *head)
{

    while (s1 != NULL && s2 != NULL)
    {

        if (s1->data < s2->data)
        {
            create(&head, s1->data);
            s1 = s1->next;
        }
        else if (s1->data > s2->data)
        {
            create(&head, s2->data);
            s2 = s2->next;
        }
        else
        {
            create(&head, s2->data);
            s1 = s1->next;
            s2 = s2->next;
        }
    }

    while (s1 != NULL)
    {
        create(&head, s1->data);
        s1 = s1->next;
    }

    while (s2 != NULL)
    {
        create(&head, s2->data);
        s2 = s2->next;
    }

    return head;
}

int main()
{
    struct node_198 *start1_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter first value of first linked list :-\n");
    scanf("%d", &start1_198->data);
    start1_198->next = NULL;

    struct node_198 *temp_1981 = start1_198;

    int x = 1;
    while (true)
    {
        printf("Do you want to add other node 1/0 :-\n");
        scanf("%d", &x);

        if (x == 0)
        {
            break;
        }

        printf("Enter the value :-\n");
        int val;
        scanf("%d", &val);
        create(&temp_1981, val);
        temp_1981 = temp_1981->next;
    }

    printf("The entered first linked list is :-\n");
    display_198(&start1_198);

    struct node_198 *start2_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter first value of second linked list :-\n");
    scanf("%d", &start2_198->data);
    start2_198->next = NULL;

    struct node_198 *temp_1982 = start2_198;

    int y = 1;
    while (true)
    {
        printf("Do you want to add other node 1/0 :-\n");
        scanf("%d", &y);

        if (y == 0)
        {
            break;
        }

        printf("Enter the value :-\n");
        int val2;
        scanf("%d", &val2);
        create(&temp_1982, val2);
        temp_1982 = temp_1982->next;
    }

    printf("The entered second linked list is :-\n");
    display_198(&start2_198);

    struct node_198 *head = NULL;
    struct node_198 *ans = merge_198(start1_198, start2_198, head);
    printf("The mergesd linked list is :-\n");
    display_198(&ans);

    return 0;
}
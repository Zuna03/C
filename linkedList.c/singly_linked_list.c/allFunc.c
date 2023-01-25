#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

// 1) Program to  Print Current List :-

void print(struct node **start)
{

    struct node *temp = *start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// 2) Program to check if the list is empty :-

void is_empty(struct node *start)
{
    if (start == NULL)
    {
        printf("Yes the list is empty. \n");
    }
    else
    {
        printf("No the list is not empty \n");
    }
}

// 3) Program to ptint the list

void create_node(struct node **start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;

    struct node *temp;

    if (*start == NULL)
    {
        *start = new;
        return;
    }
    else
    {
        temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
}

// 4) Program to Insert a node after a given data item

void insert_after(struct node **start, int n, int k)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;

    struct node *temp = *start;
    if (temp->data == k)
    {
        new->next = temp->next;
        temp->next = new;
        return;
    }
    else
    {
        while (temp->data != k)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

// 5) Program to Insert a node before a given data item

void insert_before(struct node **start, int n, int k)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;

    struct node *temp = *start;
    if (temp->data == k)
    {
        new->next = *start;
        *start = new;
        return;
    }
    else
    {
        while (temp->next->data != k)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

// 6) Program to Delete a node after a given data item

void delete_after(struct node **start, int k)
{

    struct node *temp = *start;

    while (temp->data != k)
    {
        temp = temp->next;
    }
    struct node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// 7) Program to Delete a node before a given data item

void delete_before(struct node **start, int k)
{
    struct node *temp = *start;
    struct node *temp1 = *start;
    struct node *temp2 = *start;

    if (temp->next->data == k)
    {
        struct node *toDelete = *start;
        *start = toDelete->next;
        free(toDelete);
        return;
    }
    else
    {

        while (temp2->next->data != k)
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        struct node *toDelete = temp1->next;
        temp1->next = temp2->next;
        free(toDelete);
    }
}

// 8) Program to Insert a node at the certain position (at beginning/end/any position).

void insert_certain_position(struct node **start, int n, int k)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;

    struct node *temp = *start;

    if (k == 1)
    {
        new->next = temp->next;
        temp->next = new;
        return;
    }
    else
    {
        int i = 1;
        while (i < k)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next != NULL)
        {
            new->next = temp->next;
            temp->next = new;
        }
        else
        {
            temp->next = new;
            new->next = NULL;
        }
    }
}

// 9) Program to Delete a node at the certain position (at beginning/end/any position).

void delete_at_certain_position(struct node **start, int k)
{
    struct node *temp = *start;
    if (k == 1)
    {
        struct node *toDelete = *start;
        *start = toDelete->next;
        free(toDelete);
        return;
    }
    else
    {
        int i = 1;
        while (i < k - 1)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next->next != NULL)
        {
            struct node *toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
        }
        else
        {
            struct node *toDelete = temp->next;
            temp->next = NULL;
            free(toDelete);
        }
    }
}

// 10) Program to Delete a node for the given key.

void delete_given_key(struct node **start, int k)
{
    struct node *temp = *start;

    if (temp->data == k)
    {
        struct node *toDelete = *start;
        *start = toDelete->next;
        free(toDelete);
        return;
    }
    while (temp->next->data != k)
    {
        temp = temp->next;
    }
    if (temp->next->next == NULL)
    {
        struct node *toDelete = temp->next;
        temp->next = NULL;
        free(toDelete);
    }
    else
    {
        struct node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

// 11) Program to Search for an element in the linked list.

void search_element(struct node **start, int k)
{
    struct node *temp = *start;
    int found = 0;

    while (temp != NULL)
    {
        if (temp->data == k)
        {
            found = 1;
        }
        temp = temp->next;
    }
    if (found == 1)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
}

// 12) Program to Swap the elements of the linked list

void swap(struct node *temp1, struct node *temp2)
{
    int temp = temp1->data;
    temp1->data = temp2->data;
    temp2->data = temp;
}

// 13) Program to Sort the elements of the linked list

void sort(struct node **start)
{
    struct node *temp1 = *start;
    struct node *temp2 = temp1->next;

    while (temp1->next != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp2->data < temp1->data)
            {
                swap(temp1, temp2);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

// 14) Print the elements of the linked list in the reverse order.

void print_reverse(struct node *start)
{
    struct node *temp = start;

    if (temp == NULL)
    {
        return;
    }
    print_reverse(temp->next);
    printf("%d ", temp->data);
}

// 15) Reverse the nodes of the linked list.

void reverse(struct node **start)
{
    struct node *t1 = *start;
    struct node *t2;
    struct node *t3 = NULL;

    while (t1 != NULL)
    {
        t2 = t1->next;
        t1->next = t3;
        t3 = t1;
        t1 = t2;
    }
    *start = t3;
}

// 16) Program to Print n th node from the last of a linked list.

void print_Nth_From_Last(struct node *start, int n)
{
    static int i = 0;
    if (start == NULL)
    {
        return;
    }
    print_Nth_From_Last(start->next, n);
    if (++i == n)
    {
        printf("%d", start->data);
    }
}

// 17) Program to Delete the duplicate elements in a linked list.

void remove_duplicates(struct node **start)
{
    struct node *temp1 = *start;
    struct node *temp2;

    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp1;
        while (temp2->next != NULL)
        {
            if (temp1->data == temp2->next->data)
            {
                struct node *toDelete = temp2->next;
                temp2->next = temp2->next->next;
                free(toDelete);
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}

// Main function

int main()
{
    struct node *start = (struct node *)malloc(sizeof(struct node));
    printf("Enter a value \n");
    scanf("%d", &start->data);
    start->next = NULL;

    int x = 1;

    struct node *temp = start;

    while (true)
    {

        printf("Do you want to enter another valur 1/0 ? \n");
        scanf("%d", &x);

        if (x == 0)
        {
            break;
        }

        int val;
        printf("Enter a value \n");
        scanf("%d", &val);
        create_node(&temp, val);
        temp = temp->next;
    }

    print(&temp);
    int check = 1;

    // Taking menu driven input

    printf("---------------------------------------------------------------------------------------\n");
    printf("1. Print Current List :-\n");
    printf("2. Check if the list is empty :-\n");
    printf("3. Insert a node after a given data item :-\n");
    printf("4. Insert a node before a given data item :-\n");
    printf("5. Delete a node after a given data item :-\n");
    printf("6. Delete a node before a given data item :-\n");
    printf("7. Insert a node at the certain position :-\n");
    printf("8. Delete a node at the certain position :-\n");
    printf("9. Delete a node for the given key :-\n");
    printf("10. Search for an element in the linked list :-\n");
    printf("11. Sort the elements of the linked list :-\n");
    printf("12. Print the elements of the linked list in the reverse order :-\n");
    printf("13. Reverse the nodes of the linked list :-\n");
    printf("14. Print nth node from the last of a linked list :-\n");
    printf("15. Delete the duplicate elements in a linked list :-\n");
    printf("16. Quit!!\n");
    printf("---------------------------------------------------------------------------------------\n");

    while (check)
    {

        printf("Enter a number from the above menu to execute the program that is in front of that number :- \n");

        int num;
        scanf("%d", &num);

        int new_node;
        int node_num;

        switch (num)
        {
        case 1:
            print(&start);
            printf("\n");
            break;

        case 2:
            is_empty(start);
            printf("\n");
            break;

        case 3:
            printf("Enter new node which need to be inserted\n");
            scanf("%d", &new_node);

            printf("Enter node after which new node need to be inserted\n");
            scanf("%d", &node_num);

            insert_after(&start, new_node, node_num);
            print(&start);
            printf("\n");
            break;

        case 4:
            printf("Enter new node which need to be inserted\n");
            scanf("%d", &new_node);

            printf("Enter node before which new node need to be inserted\n");
            scanf("%d", &node_num);

            insert_before(&start, new_node, node_num);
            print(&start);
            printf("\n");
            break;

        case 5:
            printf("Enter node after which a node need to be deleted \n");
            scanf("%d", &node_num);

            delete_after(&start, node_num);
            print(&start);
            printf("\n");
            break;

        case 6:
            printf("Enter node before which a node need to be deleted \n");
            scanf("%d", &node_num);

            delete_before(&start, node_num);
            print(&start);
            printf("\n");
            break;

        case 7:
            printf("Enter new node which need to be inserted\n");
            scanf("%d", &new_node);

            printf("Enter the position\n");
            scanf("%d", &node_num);

            insert_certain_position(&start, new_node, node_num);
            print(&start);
            printf("\n");
            break;

        case 8:
            printf("Enter the position\n");
            scanf("%d", &node_num);

            delete_at_certain_position(&start, node_num);
            print(&start);
            printf("\n");
            break;

        case 9:
            printf("Enter the key which needs to be deleted \n");
            scanf("%d", &node_num);
            delete_given_key(&start, node_num);
            print(&start);
            printf("\n");
            break;

        case 10:
            printf("Enter the element which is needed to be searched \n");
            scanf("%d", &node_num);

            search_element(&start, node_num);
            break;

        case 11:
            sort(&start);
            print(&start);
            printf("\n");
            break;

        case 12:
            print_reverse(start);
            break;

        case 13:
            reverse(&start);
            print(&start);
            printf("\n");
            break;

        case 14:
            printf("Enter position from the last which needs to be printrs \n");
            scanf("%d", &node_num);
            print_Nth_From_Last(start, node_num);
            printf("\n");
            break;

        case 15:
            remove_duplicates(&start);
            print(&start);
            printf("\n");
            break;

        case 16:
            printf("Quit!! \n");
            check = 0;
            break;

        default:
            printf("Invalid number \n");
            break;
        }
    }

    return 0;
}
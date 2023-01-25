#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

// to create a linked list
void create(struct node **start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;

    if (*start == NULL)
    {
        *start = new;
        return;
    }
    else
    {
        struct node *temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
}

// to display linked list
void display(struct node **start)
{
    struct node *temp = *start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// to search element of a linked list
bool search(struct node **start, int n)
{
    struct node *temp = *start;
    bool check = 0;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//  to insert element n the beginning
void insert(struct node **st, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = *st;
    *st = new;
}

// a program to search an element in a simple linked list, if found delete that node and insert that node at beginning. Otherwise display an appropriate message.
bool delete(struct node **start, int n)
{
    if (search(start, n) == false)
    {
        printf("Node which needs to be deleted is not found \n"); // displaying a message
        return 0;
    }

    else
    {
        struct node *temp;
        if ((*start)->data == n)
        {
            struct node *todelete = *start;
            *start = todelete->next;
            free(todelete);
        }
        else
        {
            temp = *start;
            while (temp->next->data != n)
            {
                temp = temp->next;
            }
            struct node *todelete = temp->next;
            temp->next = temp->next->next;
            free(todelete); // deleting the found node
        }

        insert(start, n); // insertung the found node
    }
    return 1;
}

// program to find the middle node in a single linked list
void middle(struct node **start)
{
    struct node *temp1 = (*start);
    struct node *temp2 = (*start);

    while (temp1->next != NULL && temp1->next->next != NULL)
    {
        temp1 = temp1->next->next;
        temp2 = temp2->next;
    }
    if (temp1->next == NULL)
    {
        printf("The middle node is %d\n", temp2->data);
    }
    if (temp1->next->next == NULL)
    {
        printf("The middle nodes are %d , %d\n", temp2->data, temp2->next->data);
    }
}

// program to reverse the first m elements of a linked list of n nodes.
void reverse_m(struct node **start, int m)
{
    struct node *temp = *start;
    m--;
    while (m--)
        temp = temp->next;
    struct node *joint = temp->next;
    temp->next = NULL;
    struct node *prev = NULL;
    struct node *current = *start;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *start = prev;
    struct node *temp2 = *start;
    while (temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = joint;
}

// program to check whether a given linked list is sorted or not.
bool is_sorted(struct node **start)
{
    struct node *curr = *start;
    struct node *n;

    while (curr->next != NULL)
    {
        n = curr->next;
        while (n != NULL)
        {
            if (curr->data > n->data)
            {
                return false;
            }
            n = n->next;
        }
        curr = curr->next;
    }
    return true;
}

// Given a linked list which is sorted, write a program to insert an element into the linked list in sorted way.
void insert_in_sorted(struct node **start, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;
    struct node *temp;

    if ((*start)->data > new->data)
    {
        new->next = *start;
        *start = new;
    }
    else
    {
        temp = *start;

        while (temp->next != NULL && temp->next->data <= new->data)
        {
            temp = temp->next;
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

// finding intersections elements of two linked list and store them in a third linked list.
struct node *intersection_ele(struct node *start1, struct node *start2)
{
    struct node *start3 = NULL;
    struct node *temp1 = start1;
    struct node *temp2 = start2;

    while (temp1 != NULL)
    {
        temp2 = start2;
        while (temp2 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                create(&start3, temp1->data);
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return start3;
}

// modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.
void even_before_odd(struct node **start)
{
    struct node *curr = *start;
    struct node *n;

    while (curr->next != NULL)
    {
        n = curr->next;
        while (n != NULL)
        {
            if (curr->data % 2 != 0 && n->data % 2 == 0)
            {
                int temp = curr->data;
                curr->data = n->data;
                n->data = temp;
            }
            n = n->next;
        }
        curr = curr->next;
    }
}

// a program to check whether a singly linked list is a palindrome or not.
bool is_palindrome(struct node **start)
{
    struct node *temp1 = *start;
    struct node *temp2 = *start;
    struct node *temp3;

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    if (temp1->data == temp2->data)
    {
        while (temp1 != temp2 && temp1->next != temp2)
        {
            temp2 = temp1->next;
            while (temp2->next != temp2)
            {
                temp2 = temp2->next;
            }
            if (temp2->next->data != temp1->data)
            {
                return false;
            }
            temp2 = temp2;
            temp1 = temp1->next;
        }
        if (temp1->next == temp2)
        {
            if (temp1->data == temp2->data)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

// creating cycle in a linked list
void create_cycle(struct node **start, int pos)
{
    struct node *temp = *start;
    struct node *temp2 = *start;
    int i = 1;

    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    struct node *joint = temp->next;

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = joint;
}

// detect a cycle in a linked list.
bool detect_cycle(struct node **start)
{
    struct node *slow = *start;
    struct node *fast = *start;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

// reverse only even position nodes in a singly linked list.
void reverse_even(struct node **start)
{
    struct node *odd = *start;
    struct node *even = NULL;

    while (odd != NULL && odd->next != NULL)
    {
        struct node *temp = odd->next;
        odd->next = temp->next;
        temp->next = even;
        even = temp;
        odd = odd->next;
    }

    odd = *start;
    while (even != NULL)
    {
        struct node *temp = even->next;
        even->next = odd->next;
        odd->next = even;
        odd = odd->next->next;
        even = temp;
    }
}

// swap kth node from beginning with kth node from end in a Linked List
void swap_Kth(struct node **start, int k)
{
    int i = 1;
    struct node *temp1 = *start;
    struct node *temp2 = *start;
    struct node *temp3;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    while (i < k)
    {
        temp3 = temp1->next;
        while (temp3->next != temp2)
        {
            temp3 = temp3->next;
        }
        temp2 = temp3;
        temp1 = temp1->next;
        i++;
    }
    if (i == k)
    {
        int temp = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp;
    }
}

// function to reverse every k nodes.
struct node *reverse_every_k(struct node *start, int k)
{
    if (start == NULL)
    {
        return NULL;
    }

    struct node *curr = start;
    struct node *n = NULL;
    struct node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
        count++;
    }

    if (n != NULL)
    {
        start->next = reverse_every_k(n, k);
    }

    return prev;
}

// rotate the linked list counter-clockwise by k nodes.
struct node *rotating(struct node *start, int k)
{
    if (k < 1)
    {
        return NULL;
    }
    struct node *curr = start;
    struct node *kth = NULL;
    int i = 1;
    while (i < k && curr != NULL)
    {
        curr = curr->next;
        i++;
    }
    if (curr == NULL)
    {
        return NULL;
    }
    kth = curr;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = start;
    start = kth->next;
    kth->next = NULL;
    return start;
}

int main()
{
    struct node *start = (struct node *)malloc(sizeof(struct node));
    printf("Enter first value :-\n");
    scanf("%d", &start->data);
    start->next = NULL;

    struct node *temp = start;

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
        create(&temp, val);
        temp = temp->next;
    }

    printf("The entered linked list is :-\n");
    display(&start);

    int check = 1;

    while (check)
    {

        printf("\n**************************************************************************************\n");
        printf("\t1. Print the current list.\n");
        printf("2. Write a program to search an element in a simple linked list, if found delete that node and insert that node at beginning. Otherwise display an appropriate message.\n");
        printf("3. Write a program to find the middle node in a single linked list without counting the number of nodes.\n");
        printf("4. Write a program to reverse first m elements of a linked list of n nodes.\n");
        printf("5. Write a program to check whether a given linked list is sorted or not.\n");
        printf("6. Given a linked list which is sorted, write a program to insert an element into the linked list in sorted way.\n");
        printf("7. Write a program to find the intersections elements of two linked list and store them in a third linked list.\n");
        printf("8. Write a program to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.\n");
        printf("9. Write a program to check whether a singly linked list is a palindrome or not.\n");
        printf("10. A linked list is said to contain a cycle if any node is visited more than once while traversing the list. Write a program to detect a cycle in a linked list.\n");
        printf("11. Write a program to reverse only even position nodes in a singly linked list.\n");
        printf("12. Write a program to swap kth node from beginning with kth node from end in a Linked List.\n");
        printf("13. Given a linked list, write a function to reverse every k nodes. (where k is an input to the function).\n");
        printf("14. Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer.(k<n)\n");
        printf("\t15. Quit!!\n");
        printf("\n");
        printf("\n**************************************************************************************\n");
        printf("\n");

        printf("Enter a number from above list to execute the operation in front of it :\n");
        int z;
        scanf("%d", &z);
        int k, key, m, pos, w, data;
        switch (z)
        {
        case 1:
            display(&start);
            printf("The Program ran successfully.\n");
            break;
        case 2:
            printf("Enter the key :-");
            scanf("%d", &key);
            delete(&start, key);
            display(&start);
            printf("The program ran successfully.\n");
            break;
        case 3:
            middle(&start);
            break;
        case 4:
            printf("Enter the value :-");
            scanf("%d", &m);
            reverse_m(&start, m);
            display(&start);
            printf("The program ran successfully.\n");
            break;
        case 5:
            if (is_sorted(&start))
                printf("The List is sorted.\n");
            else
                printf("The List is unsorted.\n");
            break;
        case 6:
            printf("Enter the data which need to be inserted in sorted list:- ");
            scanf("%d", &data);
            insert_in_sorted(&start, data);
            display(&start);
            printf("The program ran successfully.\n");
            break;
        case 7:
            printf("Enter the values for the second list :-\n");
            struct node *start2 = (struct node *)malloc(sizeof(struct node));
            printf("Enter a value :- ");
            scanf("%d", &start2->data);
            start2->next = NULL;
            int x2 = 1;
            struct node *temp2 = start2;
            while (true)
            {
                printf("Do you want to continue (1 = YES/ 0 = NO) :- ");
                scanf("%d", &x2);
                if (x2 == 0)
                    break;
                int val2;
                printf("Enter a value :- ");
                scanf("%d", &val2);
                create(&temp2, val2);
                temp2 = temp2->next;
            }
            struct node *start3 = intersection_ele(start, start2);
            printf("The Program ran successfully.\n");
            printf("The common linked list is :- \n");
            display(&start3);
            break;
        case 8:
            even_before_odd(&start);
            display(&start);
            printf("The Program ran successfully.\n");
            break;
        case 9:
            if (is_palindrome(&start))
                printf("The list is a palindrome.\n");
            else
                printf("The list is not a palindrome.\n");
            break;
        case 10:
            printf("Do you want to make a cycle ((0 == No) or (1 == Yes)) :-");
            scanf("%d", &w);
            if (w == 1)
            {
                printf("Enter the position where you want to create the cycle.\n");
                scanf("%d", &pos);
                create_cycle(&start, pos);
                printf("The cycle was created.\n");
            }
            if (detect_cycle(&start))
                printf("This linked list has a cycle.\n");
            else
                printf("This linked list has no cycle.\n");
            break;
        case 11:
            reverse_even(&start);
            display(&start);
            printf("The Program ran successfully.\n");
            break;
        case 12:
            printf("Enter the value :-");
            scanf("%d", &k);
            swap_Kth(&start, k);
            display(&start);
            printf("The program ran successfully.\n");
            break;
        case 13:
            printf("Enter the value :-");
            scanf("%d", &k);
            start3 = reverse_every_k(start, k);
            display(&start3);
            printf("The program ran successfully.\n");
            break;
        case 14:
            printf("Enter the value :-");
            scanf("%d", &k);
            rotating(start, k);
            printf("The program ran successfully.\n");
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    return 0;
}

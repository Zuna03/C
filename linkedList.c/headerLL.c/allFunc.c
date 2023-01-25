// Write a menu driven program to perform the following operations in a header linked
// list by using suitable user defined functions for each case. The head node keeps the
// count of the total number of nodes in the list. The data node keeps the student
// information: Name, Roll No, CGPA, Address_City, Branch.
// 1. Create
// 2. Display student information
// 3. Display the total number of nodes (in O(1) time)
// 4. Display the students’ details belonging to a particular branch
// 5. Display the students’ details securing &gt; 7.5 CGPA and belonging to a given
// branch.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node_198
{
    struct node_198 *next;
    char name[20];
    int roll;
    float cgpa;
    char address[10];
    char branch[10];
};
struct head_node
{
    int data;
    struct node_198 *next;
};

void create(struct head_node **head)
{
    char n[20];
    int r;
    float c;
    char a[10];
    char b[10];
    printf("Enter name : \n");
    scanf("%s", n);
    printf("Enter roll of student : \n");
    scanf("%d", &r);
    printf("Enter cgpa of student : \n");
    scanf("%f", &c);
    printf("Enter address of student : \n");
    scanf("%s", a);
    printf("Enter branch of student : \n");
    scanf("%s", b);
    struct node_198 *new = (struct node_198 *)malloc(sizeof(struct node_198));
    strcpy(new->name, n);
    new->roll = r;
    new->cgpa = c;
    strcpy(new->address, a);
    strcpy(new->branch, b);
    new->next = NULL;

    if ((*head)->next == NULL)
    {
        (*head)->next = new;
        ((*head)->data)++;
        return;
    }
    else
    {
        struct node_198 *temp = (*head)->next;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        ((*head)->data)++;
    }
}

void display_info(struct head_node **head)
{
    struct node_198 *temp = (*head)->next;
    while (temp != NULL)
    {
        printf("Name : %s\n", temp->name);
        printf("Roll : %d\n", temp->roll);
        printf("CGPA : %.2f\n", temp->cgpa);
        printf("Address : %s\n", temp->address);
        printf("Branch : %s\n", temp->branch);
        printf("\n");
        temp = temp->next;
    }
}

void display_total_nodes(struct head_node **head)
{
    printf("total numbers of nodes are : %d\n", (*head)->data);
}

void particular_branch(struct head_node **head, char b[10])
{
    int check = 0;
    struct node_198 *temp = (*head)->next;
    if ((*head)->next == NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(temp->branch, b) == 0)
            {
                check = 1;
                printf("Name : %s\n", temp->name);
                printf("Roll : %d\n", temp->roll);
                printf("CGPA : %.2f\n", temp->cgpa);
                printf("Address : %s\n", temp->address);
                printf("Branch : %s\n", temp->branch);
                printf("\n");
            }
            temp = temp->next;
        }
        if (temp == NULL && check == 0)
        {
            printf("No student is found of %s branch with CGPA above 7.5\n", b);
        }
    }
}

void particular_cgpa(struct head_node **head, char b[10])
{
    struct node_198 *temp = (*head)->next;
    int check = 0;
    if ((*head)->next == NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        while (temp != NULL)
        {

            if (strcmp(temp->branch, b) == 0)
            {
                if (temp->cgpa > 7.5)
                {
                    check = 1;
                    printf("Name : %s\n", temp->name);
                    printf("Roll : %d\n", temp->roll);
                    printf("CGPA : %.2f\n", temp->cgpa);
                    printf("Address : %s\n", temp->address);
                    printf("Branch : %s\n", temp->branch);
                    printf("\n");
                }
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (temp == NULL && check == 0)
        {
            printf("No student is found of %s branch.\n", b);
        }
    }
}
int main()
{
    struct head_node *head = (struct head_node *)malloc(sizeof(struct head_node));
    head->data = 0;
    head->next = NULL;

    int opt, choice;
    char ch;
    do
    {
        printf("Do you want to enter the element in the list(1->YES/0->NO):\n ");
        scanf("%d", &opt);
        if (opt == 1)
        {
            create(&head);
        }
        else
        {
            break;
        }
    } while (opt == 1);

    printf("\n1. to display student information.");
    printf("\n2. to display the total number of nodes.");
    printf("\n3. to display the students' details belonging to particular branch.");
    printf("\n4. to display the students' details securing > 7.5 CGPA and belonging to given branch.");
    do
    {
        printf("\nEnter your choice(1-4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The student list is as followed\n");
            printf("--------------------------------\n");
            display_info(&head);
            break;
        case 2:
            display_total_nodes(&head);
            break;
        case 3:
            printf("Enter the desired branch :\n");
            char b[10];
            scanf("%s", b);
            printf("The details student in %s branch are :\n", b);
            printf("--------------------------------------\n");
            particular_branch(&head, b);
            break;
        case 4:
            printf("Enter the desired branch :\n");
            char c[10];
            scanf("%s", c);
            printf("The details student in %s branch above 7.5 CGPA are : \n", c);
            printf("-----------------------------------------------------\n");
            particular_cgpa(&head, c);
            break;
        default:
            printf("\nyou entered a wrong choice!!");
            break;
        }
        printf("\n Do you want to enter more choice(Y/N): ");
        scanf("%s", &ch);
    } while (ch == 'Y' || ch == 'y');

    return 0;
}

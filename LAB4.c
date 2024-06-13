/*
    4. Write a C program to simulate the working of a singly linked list providing the following operations: a. Display
    & Insert b. Delete from the beginning/end c. Delete a given element
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to display the linked list
void display()
{
    struct node *temp = head;
    printf("\nLinked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to insert a new node at the end of the linked list
void insert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    display();
}

// Function to delete the first node of the linked list
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        display();
    }
}

// Function to delete the last node of the linked list
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
        {
            head = NULL;
        }
        else
        {
            prev->next = NULL;
        }
        free(temp);
        display();
    }
}

// Function to delete a given element from the linked list
void deleteElement(int data)
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;
        while (temp != NULL && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("\nElement not found\n");
        }
        else
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            display();
        }
    }
}

// Main function
int main()
{
    int choice, data;
    // clrscr();
    while (1)
    {
        printf("\n--------------------------------\n");
        printf("Singly Linked List Operations\n");
        printf("--------------------------------\n");
        printf("1. Insert\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Delete a given element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            deleteFromBeginning();
            break;
        case 3:
            deleteFromEnd();
            break;
        case 4:
            printf("\nEnter the data to be deleted: ");
            scanf("%d", &data);
            deleteElement(data);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice\n");
        }
    }
}

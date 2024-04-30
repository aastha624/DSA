// // 5.1 Write a program to implement following operations on the circular linked list.



#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert a node at the end of the circular linked list
void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Insert a node before specified position in the circular linked list
void insertBeforePosition(int position, int value)
{
    if (position <= 1 || head == NULL)
    {
        printf("Invalid position or empty list. Cannot insert.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 2)
    {
        newNode->next = head->next;
        head->next = newNode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1; ++i) // Corrected loop condition
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Invalid position. Cannot insert.\n");
            free(newNode);
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete the first node of the circular linked list
void deleteFirstNode()
{
    if (head == NULL)
    {
        printf("Circular linked list is empty. Cannot delete.\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = head->next;
    free(head);
    head = temp->next;
}

// Delete a node after specified position in the circular linked list
void deleteAfterPosition(int position)
{
    if (position < 1 || head == NULL)
    {
        printf("Invalid position or empty list. Cannot delete.\n");
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position && temp != NULL; ++i)
    {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != head)
    {
        struct Node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

// Display the circular linked list
void display()
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    insertAtEnd(7);
    insertAtEnd(6);
    insertAtEnd(3);
    display();

    insertBeforePosition(2, 4);
    display();

    deleteAfterPosition(3);
    display();

    deleteFirstNode();
    display();

    return 0;
}
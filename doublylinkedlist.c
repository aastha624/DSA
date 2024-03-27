// Write a program to implement following operations on the doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert a node at the front of the doubly linked list
void insertAtFront(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

// Insert a node at the end of the doubly linked list
void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete the last node of the doubly linked list
void deleteLastNode()
{
    if (head == NULL)
    {
        printf("Doubly linked list is empty. Cannot delete.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// Function to delete a node before the specified position
void deleteBeforePosition(int position)
{

    if (head == NULL || position <= 1)//empty list
    {
        printf("Invalid position or empty list. Cannot delete.\n");
        return;
    }

    if (position == 2)
    {
        struct Node *temp = head->next;
        free(head);
        head = temp;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; ++i)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Invalid position. Cannot delete.\n");
    }
    else
    {
        struct Node *toDelete = temp->prev;
        temp->prev = toDelete->prev;
        if (toDelete->prev != NULL)
        {
            toDelete->prev->next = temp;
        }
        else
        {
            head = temp; // Update head if deleting the first node
        }
        free(toDelete);
    }
}
// Display the doubly linked list
void display()
{
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertAtFront(90);
    insertAtFront(98);
    insertAtFront(32);
    display();

    insertAtEnd(45);
    insertAtEnd(85);
    display();

    deleteLastNode();
    display();

    deleteBeforePosition(2);
    display();

    return 0;
}
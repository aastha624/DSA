#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void linkedlistTraversal(struct node *ptr)
{
    while(ptr != null){
        printf("element %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    //allocate meomery for nodes in the linkedlist heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    //link first and second
    head->data = 7;
    head->next = second;

    //link second and third
    second->data = 17;
    second->next = third;

    //link third and fourth
    third->data = 45;
    third->next = fourth;

    //link fourth and null termineted list
    fourth->data = 66;
    fourth->next = null;
    return 0;
     linkedlistTraversal(head);

}


#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node*ptr){
    while(ptr!=NULL){
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

// //case 1 deletion the first node

struct node*deletfirst(struct node*head){
struct node*ptr=head;
head=head->next;
free(ptr);
return head;

}
// //case 3 delet the last index
// struct node*deletatlast(struct node*head){
//     struct node*p=head;
//     struct node*q=head->next;
//     while(q->next!=NULL){
//         p=p->next;
//         q=q->next;
//     }
//     p->next=NULL;
//     free(q);
//     return head;
// }


// //case 2 delet a node in between
// struct node * deleteAtindex(struct node * head, int index){
//     struct node *p = head;
//     struct node *q = head->next;
//     for (int i = 0; i < index-1; i++)
//     {
//         p = p->next;
//         q = q->next;
//     }
    
//     p->next = q->next;
//     free(q);
//     return head;
// }

// case 4 delet a node with a given value

// struct node * deleteAtindex(struct node * head, int value){
//     struct node *p = head;
//     struct node *q = head->next;
//     while(q->data!=value && q->next!= NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
    
//     if(q->data == value){
//         p->next = q->next;
//         free(q);
//     }
//     return head;
// }

int main(){

 struct node *head ;
 struct node*second;  
  struct node*third;  
   struct node*fourth;  
   //allocate memory for nodes in heap 
head=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc(sizeof(struct node));
fourth=(struct node*)malloc(sizeof(struct node));

//link head and second node
 head->data = 7;
 head->next = second;

 //link second and third node
  second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    linkedListTraversal(head);
    head=deletfirst(head);
    // head=deletatlast(head);
    // head=deleteAtindex(head,3);
    // head=deleteAtindex(head,2);
     linkedListTraversal(head);
    return 0;
 }

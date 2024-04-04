#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
void linkedListTraversal(struct node*ptr){
    while(ptr!=NULL){
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node * insertAtFirst(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}

//case 3 insert at the end 
// struct node * insertAtend(struct node *head, int data){
//     struct node*ptr=(struct node*)malloc(sizeof(struct node));
//     ptr->data=data;
//     struct node*p=head;
//     while(p->next!=NULL){
//         p=p->next;
//     }
//     p->next=ptr;
//     ptr->next=NULL;
//     return head;

// }

// case 3 insert in between

// struct node * insertAtindex(struct node *head, int data,int index){
//     struct node*ptr=(struct node*)malloc(sizeof(struct node));
//     ptr->data=data;
//     struct node *p=head;
//     int i = 0;

//     while (i!=index-1)//aama mostly index 1 j ganay aagal na ni aek 0 ganay
//     //je element jove che teni pachad no element thi aek oocho means aek index occhi
//     {
//         p = p->next;
//         i++;
//     }
//     ptr->data = data;
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }

// case 4 insert after node

// struct node * insertAfternode(struct node *head, struct node *q, int data){
//     struct node * ptr = (struct node *) malloc(sizeof(struct node));
//     ptr->data = data;

//     ptr->next = q->next;
//     q->next = ptr;

    
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
    // head=insertAtend(head,56);
      head=insertAtFirst(head,56);
    //  head=insertAtindex(head,56,1);
    // head=insertAfternode(head,third,56);

      linkedListTraversal(head);
    return 0;
 }

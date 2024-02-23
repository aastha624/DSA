#include<stdio.h>
#include<stdlib.h>
struct node{
    int data; 
    struct node*next;
};
struct node*top=NULL;//decleare global variable for pop
void linkedlisttraversal(struct node*ptr){
    while(ptr!=NULL){
        printf("element%d",ptr->data);
        ptr=ptr->next;
    }
}
int isempty(struct node*top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct node*top){//pass the pointer to the top node as the parameter 
    struct node*p=(struct node*)malloc(sizeof(struct node));//create new struct node 
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct node*push(struct node*top,int x){
    if(isfull(top)){
        printf("stack overflow\n");
    }
    else{
        struct node*n=(struct node*)malloc(sizeof(struct node));//create anew node*pointer n, assign new memory location in the heap
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct node*tp){
    if(isempty(tp)){
        printf("stack underflow\n");
    }
    else{
        struct node*n=tp;
        top=(tp)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
int main(){
    
top = push(top,78);
top = push(top,7);
top = push(top,8);
linkedlisttraversal(top);
int element=pop(top);
printf("popped element is%d\n",element);
linkedlisttraversal(top);
return 0;
}
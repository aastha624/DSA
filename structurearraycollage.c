#include<stdio.h>
#include<stdlib.h>
#define max 10
struct stack{
    int arr[max];
    int top;
};
void push(struct stack*st,int val){
    if(st->top<(max-1)){
         st->top++;
        st->arr[st->top] = val; 
    }
    else{
        printf("stack overflow");
    }

}
int pop(struct stack*st){
    if(st->top>=0){ 
     int val=st->arr[st->top];//top3
        st->top=st->top-1;//top2
        return val; 
    }
        
        else{
            printf("stack under flow");
        }
}
int main(){
    int val;
    printf("enter the value");
    scanf("%d",&val);
 
    struct stack s;
    s.top=-1;
    push(&s,val);
}
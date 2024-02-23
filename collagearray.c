#include<stdio.h>
#define N 5
int top;
int a[N];
void push(int val){
    if(top<(N-1)){
        top=top+1;
        a[top]=val;
    }

else{
    printf("stack is overflow");
    return;
}
}
int pop(){
    int val;
    if(top>=0){
        val=a[top];
        a[top]=0,top--;
        return val;

    }
    else{
        printf("\nstack underflow");
        return 1;
    }
}
void display(){
    int i;
    if(top==-1){
        printf("no element");
        return;
    }
    printf("\n the element of the stack are:");
    for(i=0;i<=top;i++){
        printf("%d",a[i]);
    }
}
int main(){
//int top;
//int a[N];
     top=-1;
    int r;
    printf("\n enter the data to be pushed:");
    scanf("%d",&r);
    push(r);
    //r=pop();
    
    display();

    }


#include<stdio.h>
#include<stdlib.h>
struct stack{ 
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
    return 1;
    }
    else{
    return 0;
    }
}
void push(struct stack *ptr,int val){
    if(isfull(ptr)){
        printf("stack over flow! cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val; 
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack under flow! cannot pop from the stack\n");
    return -1;
    }
    else{
        int val=ptr->arr[ptr->top];//top3
        ptr->top=ptr->top-1;//top2
        return val; 
        
    }
}


int main()
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int*)malloc(sp->size*sizeof(int));
    printf("stack has been created successfully\n");

    printf(" before pushing , full : %d\n",isfull(sp));
    printf("before pushing , Empty : %d\n",isEmpty(sp));

push(sp,56);
push(sp,56);
push(sp,56);
push(sp,56);
push(sp,6);
push(sp,56);
push(sp,56);
push(sp,56);
push(sp,56);
push(sp,98);//push 10 values 
//push(sp,46);//stack overflow since the size of the stack is 10.
    printf("after pushing , full : %d\n",isfull(sp));
    printf("after pushing , Empty :%d\n",isEmpty(sp));

    printf("popped %d from the stack\n",pop(sp));//pop ma last in first out
    printf("popped %d from the stack\n",pop(sp));
    printf("popped %d from the stack\n",pop(sp));
    return 0;
}
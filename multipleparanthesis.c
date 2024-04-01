#include<stdio.h>
#include<stdlib.h>
struct stack{ 
    int size;
    int top;
    char *arr;//ahi character array vaparay bcoz use *,+,=
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
void push(struct stack *ptr,char val){
    if(isfull(ptr)){
        printf("stack over flow! cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val; 
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack under flow! cannot pop from the stack\n");
    return -1;
    }
    else{
        char val=ptr->arr[ptr->top];//top3
        ptr->top=ptr->top-1;//top2
        return val; 
        
    }
}

int match(char a,char b){
    if(a=='{'&& b=='}'){
        return 1;
    }
    if(a=='('&& b==')'){
        return 1;
    }
    if(a=='['&& b==']'){
        return 1;
    }
    return 0;
}

int parenthesismatch(char*exp){
    //create and initialize the stack
    struct stack* sp;//create a stack pointer sp
    sp->size=100;//initialize the size member
    sp->top=-1;//initialize the top
    sp->arr=(char*)malloc(sp->size*sizeof(char));//assign the array pointer a memory location in the heap
    char popped_ch;

for(int i=0;exp[i] != '\0';i++){
    if(exp[i]=='('|| exp[i]=='{'|| exp[i]=='['){
        push(sp,exp[i]);
    }
    else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
        if(isEmpty(sp)){
            return 0;
        }
        popped_ch=pop(sp);
        if(!match(popped_ch,exp[i])){
            return 0;
        }
    }
}


if(isEmpty(sp)){
    return 1;
}
else{
    return 0;
}
}


int main(){
    char*exp= "(7-11+{23-8*2}-[33+1])";
   
    if(parenthesismatch(exp)){
        printf("matching");
    }
    else{
        printf("not matching");
    }
    return 0;
}



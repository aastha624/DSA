#include<stdio.h>
#include<stdlib.h>
struct queue{   // make structure
    int size;
    int f;
    int b;
    int*arr;//array banavava
};

int isfull(struct queue*q){
    if(q->b==q->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue*q){
    if(q->b==q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue*q,int val){
    if(isfull(q)){
        printf("queue overflow");
    }
    else{
        q->b++;
        q->arr[q->b]=val;
        printf("enqued element %d\n",val);
    }
}

int dequeue(struct queue*q){
    int a=-1;
    if(q->f==q->b){
        printf("no element in dequeue");
    }
    else{
        q->f++;
        a=q->arr[q->f];
      
    }
    return a;
}

int main(){
    struct queue q;
    q.size=100;
    q.f=q.b=-1;//koi pan element na hoi tyare val -1 hoi
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("dequeueing element %d",dequeue(&q));
    printf("dequeueing element %d",dequeue(&q));
    printf("dequeueing element %d",dequeue(&q));
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isfull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}


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
   
//BFS implemention

int node;
int i=1;
int visited[7]={0,0,0,0,0,0,0};
int a [7][7]={
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};
printf("%d",i);
visited[i]=1;
enqueue(&q,i); //enqueue i for exploration
while(!isEmpty(&q)){
    int node=dequeue(&q);
    for(int j=0;j<7;j++){
        if(a[node][j]==1 && visited[j]==0){
            printf("%d",j);
            visited[j]=1;
            enqueue(&q,j);
        }
    }
}
}

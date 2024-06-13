#include<stdio.h>
#include<stdlib.h>
int visited[7]={0,0,0,0,0,0,0};
int A [7][7]={//create 7*7 matrix adjancent 
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};
void DFS(int i){//dfs no function je aek integer lese kaya node ne visit karava mange che
    printf("%d ",i);//je visit karie aene print karavie 
    visited[i]=1;
    for(int j=0;j<7;j++){
        if(A[i][j]=1 && !visited[j]){
            DFS(j);
        }
    }
}
int main(){
    // dfs implementation
    DFS(4);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
void printarr(int *a,int n){
    for( int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}

void bubblesort(int *a,int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


int main(){
    int a[]={23 ,56 ,78 ,45 ,13 };
    int n=5;
    printarr(a,n);
    bubblesort(a,n);
    printarr(a,n);
    return 0;
}
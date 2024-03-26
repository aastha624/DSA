#include<stdio.h>
void display(int arr[],int n);
void display(int arr[],int n){
    //travesal
    for( int i=0;i<n;i++){
        printf("%d", arr[i] );
    }
    printf("\n");

}

int main(){
    int arr[100]={1,7,8,78};
    display(arr , 4);
    return 0;
}
#include<stdio.h>
 void display(int arr[],int n);
void display(int arr[],int n){
    //travesal
    for( int i=0;i<n;i++){
        printf("%d", arr[i] );
     }
     printf("\n");

}
//code of insertion
int indInsertion(int arr[], int size,int element,int capacity,int index){
    if(size>=capacity){
        printf("not succesfully");
        return -1;
        
    }
    for(int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index] = element;
    printf("  succesfully");
    return 1;
}
int main(){
    int arr[100]={7,8,12,27,88};
    int size=5,element=45,index=3;
    display(arr,size);
    indInsertion(arr,size,element,100,index);
    size +=1;
    display(arr,size);
    return 0;
}
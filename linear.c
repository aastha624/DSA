#include<stdio.h>
//array sorted hoy ke na hoy linear search chalej 
//code for linear serching
 int linearsearch(int arr[],int size,int element){
for(int i=0;i<size;i++){
    if(arr[i]==element){
        return i;
    }
}
return -1;
 }
 int main(){
    int arr[]={1,3,5,56,4,9,98,67,54,63,34};
    int size = sizeof(arr)/sizeof(int);//vadhare element hoy to size sodhava mate use karvanu
    int element=3;
    int searchIndex = linearsearch(arr,size,element);
    printf(" the element %d was found at index%d\n",element,searchIndex);
    return 0;
 }
 
#include<stdio.h>

// code for binarysearch 
// aama array must be sorted 

int binarysearch(int arr[],int size,int element) {
    int low,mid,high;
    low=0;
    high=size-1;

    //start serching

    while(low<=high){
    mid=(low+high)/2;
    if (arr[mid]==element){
        return mid;
    }
    if(arr[mid]<element){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
return -1;
}

//searching end

  int main(){
    int arr[]={1,3,5,9,24,34,44,54,65,68,98};
    int size = sizeof(arr)/sizeof(int);//vadhare element hoy to size sodhava mate use karvanu
    int element=24;
    int searchIndex = binarysearch(arr,size,element);
    printf(" the element %d was found at index %d \n",element,searchIndex);
    return 0;
 }
  
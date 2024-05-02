#include<stdio.h>
// #include<stdlib.h>
void printarray(int*a,int n){
    for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quicksort(int a[],int low,int high){
    int partitionindex;
    if(low<high){
partitionindex = partition(a, low, high); 
        quicksort(a, low, partitionindex - 1);  // sort left subarray 
        quicksort(a, partitionindex + 1, high); // sort right subarray
    
    }
}

int main(){
    int a[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3
// int a[]={9,4,4,8,7,5,6};
int n=9;// ahi n ae aaray ni under ni value
// n=7;
printarray(a,n);
quicksort(a, 0, n-1);
printarray(a,n);
return 0;
}
//find the largest element in an array
//here we will show 3 methods to find the largest element in an array brute force, sorting and using max function
//1. sort the array and return the last element
#include<iostream>
using namespace std;
//1. sort the array and return the last element
int sortArray(int arr[],int n){
    //sort the array
    //using selection sort
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    return arr[n-1];
}
//2. using max function
int maxElement(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        max=max>arr[i]?max:arr[i];
    }
    return max;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<largestElement(arr,n);
    return 0;
}

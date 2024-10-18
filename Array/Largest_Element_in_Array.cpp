//find the largest element in an array
//here we will show 3 methods to find the largest element in an array brute force, sorting and using max function
//1. sort the array and return the last element
#include<iostream>
using namespace std;
int largestElement(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<largestElement(arr,n);
    return 0;
}

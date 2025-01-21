//
#include <iostream>
using namespace std;
// time complexity O(n)
// space complexity O(1)
// int secondLargestElement(int arr[],int n){
int secondLargestElement(int arr[],int n){
    int secondLargest;
    if(n<2){
        return -1;
    }
    int largest=arr[0];
    int secondLargest=arr[1];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondLargest && arr[i]!=largest){
            secondLargest=arr[i];
        }
    }
    return secondLargest;
}
int binarySearch(int arr[],int n){
    int first=0;
    int last=n-1;
    int secondLargest;
    while(first<=last){
        int mid=(first+last)/2;
        if(arr[mid]>arr[mid+1]){
            secondLargest=arr[mid];
            break;
        }
        else if(arr[mid]<arr[mid+1]){
            first=mid+1;
        }
    }
    return secondLargest;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<binarySearch(arr,n);
    return 0;
}

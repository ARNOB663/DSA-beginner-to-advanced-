//find the second lergest array in an array
//problem link:https://www.naukri.com/code360/problems/second-largest-element-in-the-array-second-largest-element-in-the-array_5026280s
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//1. sort the array and return the second last element
int sortArray(int arr[],int n){
    //sort the array
    //using selection sort
    // time complexity O(n^2)
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
    //find the second largest element 
    int secondLargest;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]!=arr[n-1]){
            secondLargest=arr[i]; //time complexity O(n)
            break;
        }
    }
    if (secondLargest==arr[n-1]) //if all elements are same
    {
        return -1;
    }
    else
    {
        return secondLargest;
    }
}
//2. using max function more efficient than sorting the array and then returning the last element
// time complexity O(n)
int secondLargestElement(int arr[],int n){
    
    int secondLargest=arr[0];
    int small=INT_MAX,second_small=INT_MAX;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        small=min(small,arr[i]);//find the smallest element
        large=max(large,arr[i]);// find the largest element
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)//find the second smallest element
            second_small=arr[i];
        if(arr[i]>second_large && arr[i]!=large)//find the second largest element
            second_large=arr[i];
    }
    return second_large;

    
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<sortArray(arr,n)<<endl;//using sort function
    cout<<secondLargestElement(arr,n)<<endl;//using max function
    return 0;
}

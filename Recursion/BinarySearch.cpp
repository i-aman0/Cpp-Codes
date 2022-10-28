#include<iostream>
using namespace std;

bool solve(int* arr, int start, int end, int key){
    int mid=start+(end-start)/2;

    if(start>end){
        return false;
    }

    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]<key){
        return solve(arr, mid+1, end, key);
    }
    else{
        return solve(arr, start, mid-1, key);
    }
}

bool binarySearch(int* arr, int size, int key){
    return solve(arr, 0, size-1, key);
}

int main()
{
    int arr[]={3,5,7,8,23};
    int size=5;
    int key;
    cout<<"Enter the number you want to search"<<endl;
    cin>>key;

    if(binarySearch(arr, size, key)){
        cout<<"The key is present in the array"<<endl;
    }
    else{
        cout<<"The key is not present in the array"<<endl;
    }

    return 0;
}
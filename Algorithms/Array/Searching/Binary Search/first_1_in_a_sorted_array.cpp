// Given a sorted array of 0s and 1s, find the index of first occurence of 1 
// first approach is to find using linear search -- O(n)
// but since the array is sorted we can use binary sort to find the first occurence of 1  -- O(log n)
#include<iostream>
using namespace std;

int binarys(int arr[], int n)
{
    int low=0;
    int high=n-1;
    int mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==1 && (arr[mid-1]==0 || mid==0))
        {
            return mid;
        }
        if(arr[mid]==0)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
    
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int index=binarys(arr,n);
    if(index==-1)
    {
        cout<<"1 is not present in the array"<<endl;
    }
    else
    {
        cout<<"The first 1 is present at index "<<index<<endl;
    }
    return 0;
}
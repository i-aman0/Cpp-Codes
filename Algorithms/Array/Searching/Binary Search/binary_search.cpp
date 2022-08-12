#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int item)
{
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high) //i.e. keep searching until low and high converge
    {
        mid=(low+high)/2;
        if(arr[mid]==item)
        {
            return mid;
        }
        if(arr[mid]<item)
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
    int n,item;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter sorted array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched : "<<endl;
    cin>>item;

    int index=binary_search(arr,n,item);
    
    if(index==-1)
    {
        cout<<"Element "<<item<<" not found in the array"<<endl;
    }
    else
    {
        cout<<"Element "<<item<<" is found at index "<<index<<endl;
    }
    return 0;
}
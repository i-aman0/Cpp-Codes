// Given a sorted array of distinct integers, sort the array in wave like form
// e.g. arr={1,2,3,4,5} o/p={2,1,4,3,5}

#include<iostream>
using namespace std;

void print(int arr[], int n)
{
    cout<<"The array sorted in wave form is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void wave(int arr[], int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(i>0 && arr[i]<arr[i-1])
        {
            int temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
        }
        if(i<n-1 && arr[i]<arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }

    print(arr,n);

}

int main()
{
    int n;
    cout<<"Enter the number of elements of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the sorted elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    wave(arr,n);
    return 0;
}
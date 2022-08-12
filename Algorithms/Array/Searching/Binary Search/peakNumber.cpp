/* given an array such that the elements stored in the array are in increasing order initially and then after reaching to a peak value, 
   elements stored are in descending order, e.g. 12345421*/
// find the highest elememt in the array i.e. 5

//hint: use binary search to find out a number that is greater than its surroundings

#include<iostream>
using namespace std;

int findMax(int n, int a[])
{
    int low=0, high=n;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
        {
            return a[mid];
        }
        if(a[mid]>a[mid-1] && a[mid]<a[mid+1])
        {
            low=mid+1;
        }
        if(a[mid]<a[mid-1] && a[mid]>a[mid+1])
        {
            high=mid-1;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array first in ascending and then in descending order"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=findMax(n, arr);
    cout<<"The highest number in the array is : "<<ans<<endl;
    return 0;
}
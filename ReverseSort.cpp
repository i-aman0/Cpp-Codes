#include<iostream>
using namespace std;

int main()
{
    int arr[]={4,2,3,1,6,8,7,5,9,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n, greater<int>());
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;

}
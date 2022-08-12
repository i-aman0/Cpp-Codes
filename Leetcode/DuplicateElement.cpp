#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int s1=n*(n+1)/2; 
    int s2=0;
    for(int i=0;i<n;i++)
    {
        s2+=arr[i];
    }
    cout<<"The duplicate element is : ";
    cout<<n-(s1-s2)<<endl;
    return 0;
}

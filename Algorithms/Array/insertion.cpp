#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the Size of Array"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the Elements of Array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"The Original array is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    int index,item;
    cout<<"Enter the Item to be inserted and index at which to be inserted"<<endl;
    cin>>item>>index;
    for(int i=n;i>index;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[index]=item;
    n=n+1;
    
    cout<<"The new Array after insertion is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;

}
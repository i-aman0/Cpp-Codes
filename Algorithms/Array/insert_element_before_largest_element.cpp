#include<iostream>
using namespace std;

int size,n;
int* arr;

void print()
{
    cout<<"* * * * * * ARRAY * * * * * *"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int largest()
{
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[index])
        index=i;
    }
    return index;
}

void insert_before_largest(int item, int index)
{
    for(int i=n-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=item;
    n=n+1;
}

int main()
{
    int item,index;
    int size;
    cout<<"Enter the size of Array"<<endl;
    cin>>size;

    arr=new int[size];

    cout<<"Enter the Number of elements you want to store in the array"<<endl;
    cin>>n;

    cout<<"Enter the Elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //print();

    index=largest();

    cout<<"Enter the item you want to enter"<<endl;
    cin>>item;

    insert_before_largest(item,index);
    print();

    return 0;



}
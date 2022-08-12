#include<iostream>
using namespace std;

int* arr;
int size,n;

void print()
{
    cout<<"\n ******* Array *******"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void bubble_sort()
{
    bool flag=true;
    for(int i=0; flag && i<n-1;i++)
    {
        flag=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=true;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        print();
    }
}

int main()
{
    cout<<"Enter the size of array"<<endl;
    cin>>size;

    arr=new int[size];

    cout<<"Enter number of elements to be stored in the array"<<endl;
    cin>>n;

    cout<<"Enter the Elements of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    print();
    cout<<endl;
    
    bubble_sort();
    print();

}
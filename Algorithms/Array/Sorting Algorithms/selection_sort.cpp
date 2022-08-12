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

void selection_sort()
{
    for(int i=0;i<n-1;i++)
    {
        int min=i; //index of minimum element
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
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


    cout<<endl;

    selection_sort();
    print();
}
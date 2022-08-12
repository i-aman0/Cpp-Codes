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

void insertion_sort_ascending()
{
    for(int j=1;j<n;j++)
    {
        int key=arr[j];
        int i=j-1;
        while(i>=0 && key<arr[i])
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
        print();
    }
}

/*void insertion_sort_descending()
{
    for(int j=1;j<n;j++)
    {
        int key=arr[j];
        int i=j-1;
        while(i>=0 && key>arr[i])
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
        print();
    }
}*/

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
    
    cout<<"ASCENDING ORDER"<<endl;
    insertion_sort_ascending();
    
    //cout<<"DESCENDING ORDER"<<endl;
    //insertion_sort_descending();
    //print();

    return 0;

}
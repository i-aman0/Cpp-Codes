// The commented out code is for local declaration of array and other variables
#include<iostream>
using namespace std;

//int size,n;
//int* arr;

void print(int arr[], int n) //to print the array, for local: void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insert(int arr[], int n, int item, int index)
{
    for(int i=n-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=item;
    n=n+1;
}

void delete_at_index(int arr[], int n, int index)
{
    for(int i=index;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    n=n-1;
}

int search(int arr[], int n, int item)
{
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(item==arr[i])
        {
            pos=i;
            break;
        }
    }
    return pos;
}

void delete_item(int arr[], int n, int item)
{
    int index=search(arr, n, item);
    if(index!=-1)
    {
        delete_at_index(arr, n, index);
    }
    else
    {
        cout<<endl<<"Item not present in the array"<<endl;
    }
}

int main()
{
    int *arr;
    int size,n;
    cout<<"Enter the size of array"<<endl;
    cin>>size;

    arr=new int[size]; //creating dynamic array using new operator
    memset(arr, 0, size);

    cout<<"Enter the number of elements to be stored in array"<<endl;
    cin>>n;

    cout<<"Enter the Elements of Array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"The Original array is : ";
    print(arr, n);
    cout<<endl;

    insert(arr, n, 20,3);
    cout<<"The Array after insertion is : ";
    print(arr, n); //print(arr,n);

    delete_at_index(arr, n, 3);
    cout<<endl;
    cout<<"The array after deleting index 3 element is : ";
    print(arr, n-1);

    delete_item(arr, n, 90);
    cout<<endl;
    cout<<"The final array is : ";
    print(arr, n-1);

}
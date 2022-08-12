// The commented out code is for local declaration of array and other variables
#include<iostream>
using namespace std;

int size,n;
int* arr;

void print() //to print the array, for local: void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insert(int item, int index)
{
    for(int i=n-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=item;
    n=n+1;
}

void delete_at_index(int index)
{
    for(int i=index;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    n=n-1;
}

int search(int item)
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

void delete_item(int item)
{
    int index=search(item);
    if(index!=-1)
    {
        delete_at_index(index);
    }
    else
    {
        cout<<endl<<"Item not present in the array"<<endl;
    }
}

int main()
{
    //int *arr;
    //int size,n;
    cout<<"Enter the size of array"<<endl;
    cin>>size;

    arr=new int[size]; //creating dynamic array using new operator

    cout<<"Enter the number of elements to be stored in array"<<endl;
    cin>>n;

    cout<<"Enter the Elements of Array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"The Original array is : ";
    print();
    cout<<endl;

    insert(20,3);
    cout<<"The Array after insertion is : ";
    print(); //print(arr,n);

    delete_at_index(3);
    cout<<endl;
    cout<<"The array after deleting index 3 element is : ";
    print();

    delete_item(90);
    cout<<endl;
    cout<<"The final array is : ";
    print();

}
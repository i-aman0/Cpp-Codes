#include<iostream>
using namespace std;


// Worst case complexity i.e. element found at last -- O(n)
// Element not found ki complexity -- O(n)
/*int linear_search(int arr[], int n, int item)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==item)
        {
            return i;
        }
    }
    return -1;
}*/


//Element found at last -- O(1)
//Element not found -- O(n/2)
int linear_search(int arr[], int n, int item)
{
    int left=0;
    int right=n-1;
    for(left=0;left<=right;)
    {
        if(arr[left]==item)
        {
            return left;
        }
        if(arr[right]==item)
        {
            return right;
        }
        left++;
        right--;
    }
    return -1;
}
int main()
{
    int n,item;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter the element to be searched : "<<endl;
    cin>>item;

    int index=linear_search(arr,n,item);
    /*if(index==-1)
    {
        cout<<"Element "<<item<<" not present in the array"<<endl;
    }
    else
    {
        cout<<"Element "<<item<<" is present at index "<<index<<endl;
    }*/
    (index==-1)?cout<<"Element "<<item<<" is not present in the array"<<endl:cout<<"Element "<<item<<" is present at index "<<index<<endl;
    return 0;
}
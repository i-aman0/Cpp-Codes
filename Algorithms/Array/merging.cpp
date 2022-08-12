#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cout<<"Enter the number of elements in two Arrays"<<endl;
    cin>>n1>>n2;
    int a[n1],b[n2],c[n1+n2];
    cout<<"Enter the first Sorted Array"<<endl;
    for(int i=0;i<n1;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the second Sorted Array"<<endl;
    for(int i=0;i<n2;i++)
    {
        cin>>b[i];
    }
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            c[k]=a[i];
            i++;
        }
        else
        {
            c[k]=b[j];
            j++;
        }
        k++;
    }
    if(i==n1)
    {
        while (j<n2)
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<n1)
        {
            c[k]=a[i];
            i++;
            k++;
        }
    }
    cout<<"The Merged Array is : "<<endl;
    for(int i=0;i<(n1+n2);i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
// Time complexity = O(log n)

#include<iostream>
using namespace std;

int hcf(int n1, int n2)
{
    if(n2==0)
    {
        return n1;
    }
    else
    {
        return (hcf(n2,n1%n2));
    }
}

int main()
{
    int n1,n2;
    cout<<"Enter the first number"<<endl;
    cin>>n1;
    cout<<"Enter the second number"<<endl;
    cin>>n2;

    if(n1>n2)
    {
        cout<<"The HCF of "<<n1<<" and "<<n2<<" is : "<<hcf(n1,n2)<<endl;
    }
    else
    {
        cout<<"The HCF of "<<n1<<" and "<<n2<<" is : "<<hcf(n2,n1)<<endl;
    }

    return 0;
}
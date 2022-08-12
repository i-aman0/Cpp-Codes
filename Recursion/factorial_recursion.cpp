#include<iostream>
using namespace std;

int fac(int num)
{
    if(num==0)
    {
        return 1;
    }
    else
    {
        return (num*fac(num-1));
    }
}

int main()
{
    int n;
    cout<<"Enter the Number to find the factorial"<<endl;
    cin>>n;
    cout<<"The Factorial of "<<n<<" is : "<<fac(n)<<endl;
}
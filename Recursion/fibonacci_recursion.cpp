#include<iostream>
using namespace std;

int fib(int t)
{
    if(t==0 || t==1)
    {
        return t;
    }
    else
    {
        return(fib(t-2)+fib(t-1));
    }
}

int main()
{
    int term;
    cout<<"Enter which term you want to find"<<endl;
    cin>>term;

    cout<<"The "<<term<<"th term of fibonacci series is : "<<fib(term-1)<<endl;
}
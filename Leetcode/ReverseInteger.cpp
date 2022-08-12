#include<iostream>
#include<limits>

using namespace std;

int ReverseNumber(int n)
{
    int rev=0;
    while (n!=0)
    {
        int digit=n%10;
        if((rev<INT_MIN/10)||(rev>INT_MAX/10))
        {
            return 0;
        }
        rev=rev*10+digit;
    }
    return rev;
    
}

int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    int ans=ReverseNumber(n);
    if(ans==0)
    {
        cout<<"The reverse of the number is out of bound"<<endl;
    }
    else
    {
        cout<<"The reverse of "<<n<<" is "<<ans<<endl;
    }
    return 0;
}
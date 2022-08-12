#include<iostream>
using namespace std;

string repeat(string s, int n)
{
    int q=n/s.length();
    int r=n%s.length();
    string p;
    for(int i=0;i<q;i++)
    {
        p+=s;
    }
    string x;
    for(int i=0;i<r;i++)
    {
        x+=s[i];
    }
    return p+x;
}

int main()
{
    string str1;
    cout<<"Enter the string"<<endl;
    cin>>str1;
    int n;
    cout<<"Enter the number of times you want to repeat the string"<<endl;
    cin>>n;
    string str2=repeat(str1,n);
    cout<<"The repeated string is : "<<str2<<endl;
    return 0;
}
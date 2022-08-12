#include<iostream>
using namespace std;

bool isPalindrome(string str)
{
    int s=str.length();
    for(int i=0;i<s/2;i++)
    {
        if(str[i]!=str[s-i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    cin>>str;
    if(isPalindrome(str))
    {
        cout<<"The string \""<<str<<"\" is palindrome"<<endl;
    }
    else
    {
        cout<<"The string \""<<str<<"\" is not palindrome"<<endl;
    }
    return 0;
}
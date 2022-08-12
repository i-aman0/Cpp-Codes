#include<iostream>
using namespace std;

string swapStr(string str)
{
    if(str.length()%2==0)
    {
        for(int i=0;i<str.length();i+=2)
        {
            char temp=str[i];
            str[i]=str[i+1];
            str[i+1]=temp;
        }
    }
    else
    {
        for(int i=0;i<str.length()-1;i+=2)
        {
            char temp=str[i];
            str[i]=str[i+1];
            str[i+1]=temp;
        }
    }
    return str;
}

string encodeStr(string str)
{
    string str1="";
    for(int i=0;i<str.length();i++)
    {
        //str1[i]='Z' - str[i] + 'A';
        char ch='Z'-str[i]+'A';
       // cout<<ch;
        str1=str1+ch;
    }
    cout<<endl;
    return str1;
}

int main()
{
    string str="ABCEFDG";
    str=swapStr(str);
    cout<<"The swapped string is : "<<str<<endl;


    str=encodeStr(str);
    cout<<"The encoded String is : "<<str<<endl;
    return 0;
}
#include<iostream>
using namespace std;

string mergeString(string str1, string str2)
{
    int n=max(str1.size(), str2.size());
    string ans="";
    for(int i=0;i<n;i++)
    {
        if(i<str1.size())
        {
            ans+=str1[i];
        }
        if(i<str2.size())
        {
            ans+=str2[i];
        }
    }
    return ans;
}

int main()
{
    string str1="abcd";
    string str2="efghijk";

    cout<<"After merging the strings the result is : "<<mergeString(str1, str2)<<endl;
    return 0;
}
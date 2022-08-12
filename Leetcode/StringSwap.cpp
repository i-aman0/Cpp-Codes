#include<iostream>
using namespace std;

bool areAlmostEqual(string s1, string s2)
{
    int count=0;
    if(s1==s2)
    {
        return true;
    }

    else if(s1.length()==2)
    {
        if(s1[0]==s2[1] && s2[0]==s1[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //return false;
}

int main()
{
    string s1="aa";
    string s2="ac";
    bool flag=areAlmostEqual(s1, s2);
    cout<<flag<<endl;
    return 0;
}
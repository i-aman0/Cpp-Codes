#include<iostream>
using namespace std;

class Solution
{
    public:

    int min_index_char(string str, string patt)
    {
        int len=patt.length();
        int ind[len];
        for(int i=0;i<len;i++)
        {
            ind[i]=INT_MAX;
        }
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<str.length();j++)
            {
                if(patt[i]==str[j])
                {
                    ind[i]=j;
                    break;
                }
            }
        }
        sort(ind,ind+len);
        if(ind[0]==INT_MAX)
        {
            return -1;
        }
        else
        {
            return ind[0];
        }

    }
};

int main()
{
    int t;
    cout<<"Enter the number of test cases : ";
    cin>>t;
    while (t--)
    {
        string str;
        string patt;
        cout<<"Enter Original String : ";
        cin>>str;
        cout<<"Enter string from which to search : ";
        cin>>patt;
        Solution obj;
        cout<<obj.min_index_char(str,patt)<<endl;

    }

    return 0;
    
}
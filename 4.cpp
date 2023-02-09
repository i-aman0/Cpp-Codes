#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;

int solve(string str)
{
    int curr = 0; // curr will point where same char came again
    string str1 = "";
    string str2 = "";
    unordered_set<char> s1;
    for (int i = 0; i < str.length(); i++)
    {
        // if already present then break string from there
        if (s1.find(str[i]) != s1.end())
        {
            break;
        }
        else
        {
            s1.insert(str[i]);
            curr++;
            str1.push_back(str[i]);
        }
    }

    // now make str2
    for (curr; curr < str.length(); curr++)
    {
        str2.push_back(str[curr]);
    }

    // cout << "string 1 is " << str1 << endl;
    // cout << "string 2 is " << str2 << endl;

    // now find uniqure characters in str2 and add its length to str1 length
    unordered_set<char> s2;
    for (int i = 0; i < str2.size(); i++)
    {
        s2.insert(str2[i]);
    }

    int len1 = str1.length();
    int len2 = s2.size();
    // cout << "string 1 size is " << len1 << endl;
    // cout << "string 2 size is " << len2 << endl;

    return len1+len2;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int x;
        cin >> x;
        string str = "";
        for (int i = 0; i < x; i++)
        {
            char c;
            cin >> c;
            str.push_back(c);
        }
        cout << solve(str) << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
#include<iostream>

#define ll long long
#define mod 1e9 + 7

using namespace std;

// https://codeforces.com/problemset/problem/71/A

// void v(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     srand((unsigned int)time(NULL));
// }

using namespace std;

string solve(string &s){
    if(s.length() <= 10){
        return s;
    }

    string ans;

    ans += s[0];
    ans += to_string(s.length() - 2);
    ans += s[s.length() - 1];

    return ans;
}

int main(){
    //v();

    int t;
    cin >> t;

    while(t--){
        string str;
        cin >> str;
        cout << solve(str) << endl;
    }
    
    return 0;
}
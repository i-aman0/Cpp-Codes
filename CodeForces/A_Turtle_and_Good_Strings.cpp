#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;

// https://codeforces.com/contest/2003/problem/A


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string str;
        cin >> str;

        if(str[0] != str[n - 1]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
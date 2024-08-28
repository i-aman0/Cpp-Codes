#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;

// https://codeforces.com/problemset/problem/1712/B


int main(){
    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> ans;

        if(n % 2){
            ans.push_back(1);

            for(int i = 1; i < n; i += 2){
                ans.push_back(i + 2);
                ans.push_back(i + 1);
            }
        }
        else{
            for(int i = 0; i < n; i += 2){
                ans.push_back(i + 2);
                ans.push_back(i + 1);
            }
        }

        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }

        cout << endl;

        
    }

    return 0;
}


/*
    if n is odd (n % 2) e.g n == 5
    1, 3, 2, 5, 4
    if n is even e.g. n == 6
    2, 1, 4, 3, 6, 5

*/
#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;

// https://codeforces.com/contest/1999/problem/C


int main(){
    ll t;
    cin >> t;

    while(t--){
        int n, s, m;
        cin >> n;
        cin >> s;
        cin >> m;

        vector<pair<ll, ll>> intervals;

        for(ll i = 0; i < n; i++){
            ll l, r;
            cin >> l >> r;
            intervals.push_back({l, r}); 
        }

        ll prev = 0;
        bool canShower = false;

        for (auto interval : intervals){
            if(prev + s <= interval.first){
                canShower = true;
                break;
            }

            prev = interval.second;
        }

        if(prev + s <= m){
            canShower = true;
        }

        if(canShower){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
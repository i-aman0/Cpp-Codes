#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;


int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        vector<ll> b(n);
        ll minA = INT_MAX;
        ll minB = INT_MAX;

        for(ll i = 0; i < n; i++){
            cin >> a[i];
            minA = min(minA, a[i]);
        }

        for(ll i = 0; i < n; i++){
            cin >> b[i];
            minB = min(minB, b[i]);
        }

        vector<ll> diffA(n);
        vector<ll> diffB(n);

        for(ll i = 0; i < n; i++){
            diffA[i] = a[i] - minA;
            diffB[i] = b[i] - minB;
        }

        ll ans = 0;

        for(ll i = 0; i < n; i++){
            if(diffA[i] >= diffB[i]){
                ans += diffA[i];
            }
            else{
                ans += diffB[i];
            }
        }

        cout << ans << endl;
    }

    return 0;
}
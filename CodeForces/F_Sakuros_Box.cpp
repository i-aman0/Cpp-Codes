#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
const int mod = 1e9 + 7;

using namespace std;

ll modExp(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);

        ll sum = 0, sumSquare = 0;

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
            sum %= mod;
            sumSquare += arr[i] * arr[i];
            sumSquare %= mod;
        }

        sum %= mod;
        sumSquare %= mod;

        ll numPairs = (n * (n - 1) / 2) % mod;
        ll numerator = (sum * sum - sumSquare) % mod;
        numerator = (numerator + mod) % mod;
        
        ll denominator = (2 * numPairs) % mod;
        
        ll denominatorInv = modExp(denominator, mod - 2, mod);

        ll ans = (numerator * denominatorInv) % mod;
        
        cout << ans << endl;
    }

    return 0;
}
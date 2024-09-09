#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;

ll maxLength(ll l, ll r){
    int len = 1;
    int diff = 1;

    while (l + diff <= r) {
        l += diff;
        diff++;
        len++;
    }

    return len;
}


int main(){
    ll t;
    cin >> t;

    while(t--){
        ll l, r;
        cin >> l >> r;

        ll maxLen = maxLength(l, r);
        cout << maxLen << endl;
    }

    return 0;
}
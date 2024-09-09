#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;

bool isPerfectSquare(ll n) {
    ll root = sqrt(n);
    return root * root == n;
}

bool isBeautifulMatrix(string s, ll k) {
    // Check first and last rows
    for (ll j = 0; j < k; ++j) {
        if (s[j] != '1' || s[(k-1)*k + j] != '1') {
            return false;
        }
    }

    // Check first and last columns
    for (ll i = 0; i < k; ++i) {
        if (s[i*k] != '1' || s[i*k + (k-1)] != '1') {
            return false;
        }
    }

    // Check inside elements
    for (ll i = 1; i < k-1; ++i) {
        for (ll j = 1; j < k-1; ++j) {
            if (s[i*k + j] != '0') {
                return false;
            }
        }
    }

    return true;
}


int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;

        if(!isPerfectSquare(n)){
            cout << "NO" << endl;
            continue;
        }

        ll k = sqrt(n);

        if(isBeautifulMatrix(s, k)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }


    return 0;
}
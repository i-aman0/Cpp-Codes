#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll startYear = n - k + 1;
        ll endYear = n;

        ll numberOfLeaves = (endYear * (endYear + 1)) / 2 - ((startYear - 1) * startYear) / 2;

        if (numberOfLeaves % 2) {
            cout << "NO" << endl;
        } 
        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
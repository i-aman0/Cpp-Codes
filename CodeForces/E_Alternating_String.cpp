#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;

ll minOps(string str, ll n){
    if(n == 1){
        return 1;
    }

    ll evenMis = 0;
    ll oddMis = 0;

    for(ll i = 0; i < n; i += 2){
        if(str[i] != str[0]){
            evenMis++;
        }
    }

    for(ll i = 1; i < n; i += 2){
        if(str[i] != str[1]){
            oddMis++;
        }
    }

    int minOps = INT_MAX;

    if (n % 2 != 0) {
        // Try removing each character and calculate the result
        for (int i = 0; i < n; i++) {
            string t = str.substr(0, i) + str.substr(i + 1);
            int localOperations = 0;
            for (int j = 0; j < t.size(); j++) {
                if (j % 2 == 0 && t[j] != t[0]) localOperations++;
                if (j % 2 != 0 && t[j] != t[1]) localOperations++;
            }
            minOps = min(minOps, localOperations + 1);
        }
    }

    return minOps;
}


int main(){
    ll t;
    cin >> t;

    while(t--){
       ll n;
       cin >> n;
       string str;
       cin >> str;

       ll ans = minOps(str, n);

       cout << "The answer is : ";
       cout << ans << endl;
    }

    return 0;
}
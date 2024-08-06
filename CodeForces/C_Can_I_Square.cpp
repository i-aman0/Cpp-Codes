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

        vector<ll> buckets(n);

        for(ll i = 0; i < n; i++){
            cin >> buckets[i];
        }

        ll sum = 0;

        for(ll i = 0; i < n; i++){
            sum += buckets[i];
        }

        if(ceil(sqrt(sum)) == floor(sqrt(sum))){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
#include<iostream>

#define ll long long int
using namespace std;

ll countPizza(vector<ll> &r, int time){
    
}

int main(){
    int t;
    cout << "Enter the number of test casees" << endl;
    cin >> t;

    while(t--){
        ll n; // number of rotis
        cin >> n;
        ll k; // number of chefs
        cin >> k;

        vector<ll> r(k); // rank of chefs

        for(int i = 0; i < k; i++){
            cin >> r[i];
        }

        sort(r.begin(), r.end());

        ll s = 1;
        ll e = r[0] * n * (n + 1) / 2;

        ll ans = 0;

        while(s <= e){
            ll mid = (s + e) / 2;

            if(countPizza(r, mid) > n){
                e = mid - 1;
            }
        }
    }

    return 0;
}
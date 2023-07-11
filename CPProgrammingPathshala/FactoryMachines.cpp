#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

// https://cses.fi/problemset/task/1620

void v(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
}

using namespace std;

int main(){
    v();

    ll n;
    ll t;
    cin >> n >> t;

    vector<ll> time(n);

    for(ll i = 0; i < n; i++){
        cin >> time[i];
    }

    ll s = 0;
    ll e = 1e18;

    ll ans = 0;

    while(s <= e){
        ll mid = (s + e) / 2;
        ll sum = 0;

        for(int i = 0; i < n; i++){
            sum += mid / time[i];

            if(sum >= t){
                break;
            }
        }

        if(sum >= t){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
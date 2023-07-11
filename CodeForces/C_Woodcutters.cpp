#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

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
    cin >> n;

    vector<pair<ll, ll> > height(n + 2);

    height[0].first = -1e15;
    height[0].second = 0;

    for(ll i = 1; i <= n; i++){
        ll f, s;
        cin >> f >> s;

        height[i].first = f;
        height[i].second = s;
    }

    height[n + 1].first = 1e15;
    height[n + 1].second = 0;

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        if(height[i].first - height[i].second > height[i - 1].first){
            ans++;
        }
        else if(height[i].first + height[i].second < height[i + 1].first){
            ans++;
            height[i].first += height[i].second;
        }
    }

    cout << ans << "\n";
    
    // return 0;
}
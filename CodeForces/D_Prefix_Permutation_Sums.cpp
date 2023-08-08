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

vector<ll> prefixSumToArray(vector<ll> &pre, ll n){
    vector<ll> res(n);

    res[0] = pre[0];
    for (int i = 1; i < n; ++i) {
        res[i] = pre[i] - pre[i - 1];
    }
    return res;
}

bool isPermutation(vector<ll> &pre, ll n){
    for(int i = 0; i < n; i++){
        if(pre[i] < 0 || pre[i] > n){
            return false;
        }
    }

    set<ll> s(pre.begin(), pre.end());

    return s.size() == n;
}

void solve(){
    ll n;
        cin >> n;

        vector<ll> pre(n - 1);

        for(int i = 0; i < n - 1; i++){
            cin >> pre[i];
        }

        ll s1 = n * (n + 1) / 2;

        if(pre.back() != s1){
            pre.push_back(s1);
            
            vector<ll> b = prefixSumToArray(pre, n);

            if(isPermutation(b, n)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }

            return;
        }

        map<ll, int> count;

        count[pre[0]]++;

        for(int i = 1; i < n - 1; i++){
            count[pre[i] - pre[i - 1]]++;
        }

        vector<int> count1;

        for(auto p : count){
            if(p.second > 1){
                count1.push_back(p.first);
            }
        }

        if(count1.size() > 1){
            cout << "NO" << endl;
            return;
        }

        if(count1.size() == 1){
            int x1 = count1[0];

            if(count[x1] > 2){
                cout << "NO" << endl;
                return;
            }
        }

        vector<int> count0;

        for(int i = 1; i <=n; i++){
            if(count[i] == 0){
                count0.push_back(i);
            }
        }

        if(count0.size() != 2){
            cout << "NO" << endl;
            return;
        }

        cout << "YES" << endl;
}

int main(){
    // v();

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    
    return 0;
}
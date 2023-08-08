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

// n -- number of people
// m -- number of steps
// k -- height diff btw neighbouring steps
// h -- vlad's height

int main(){
    // v();

    int t;
    cin >> t;

    while(t--){
        int n, m, k, h;
        cin >> n >> m >> k >> h;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(h != arr[i] && abs(h - arr[i]) % k == 0 && abs(h - arr[i]) <= (m - 1) * k){
                ans++;
            }
        }

        cout << ans << endl;

    }

    
    return 0;
}
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

// https://codeforces.com/problemset/problem/1744/A

bool solve(vector<int> &arr, string &s){
    int n = *max_element(arr.begin(), arr.end());
    vector<int> dp(n + 1, 0);

    string res;

    for(int i = 0; i < arr.size(); i++){

        if(dp[arr[i]] == 0){
            dp[arr[i]] = s[i];
            res += s[i];
        }
        else{
            res += dp[arr[i]];
        }
    }

    return res == s;
}

int main(){
    // v();

    int t;
    cin >> t;
    while(t--){
        int n;
        string s;

        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cin >> s;

        if(solve(arr, s)){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

// void v(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     srand((unsigned int)time(NULL));
// }

using namespace std;



int main(){
    //v();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string str;
        cin >> str;

        map<char, int> m;

        for(int i = 0; i < n; i++){
            m[str[i]]++;
        }

        int ans = 0;

        for(auto it : m){
            ans += 2;
            if(it.second > 1){
                ans += (it.second - 1);
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
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

        vector<int> candies(n);

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            candies[i] = temp;
        }

        sort(candies.begin(), candies.end());

        int ans = 0;

        for(int i = 1; i < n; i++){
            ans += candies[i] - candies[0];
        }

        cout << ans << endl;
    }

    
    return 0;
}
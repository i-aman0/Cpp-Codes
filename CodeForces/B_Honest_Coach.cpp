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

        vector<int> s(n);

        for(int i = 0; i < n; i++){
            cin >> s[i];
        }

        sort(s.begin(), s.end());

        int diff = INT_MAX;

        for(int i = 1; i < n; i++){
            if(s[i] - s[i - 1] < diff){
                diff = s[i] - s[i - 1];
            }
        }

        cout << diff << endl;
    }

    
    return 0;
}
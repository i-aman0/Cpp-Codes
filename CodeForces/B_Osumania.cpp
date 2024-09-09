#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> ans;

        for(int i = 0; i < n; i++){
            string row;
            cin >> row;

            for(int j = 0; j < 4; j++){
                if (row[j] == '#') {
                    ans.push_back(j + 1);
                    break;
                }
            }
        }

        for(int i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
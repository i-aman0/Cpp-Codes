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
    // v();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        string s;
        cin >> s;

        string ans;

        int i = 0;
        while(i < s.length()){
            char ch = s[i];
            i++;

            while(s[i] != ch){
                i++;
            }

            i++;
            ans.push_back(ch);
        }

        cout << ans << "\n";
    }

    
    return 0;
}
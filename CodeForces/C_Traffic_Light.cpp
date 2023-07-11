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

int solve(string &str, char ch){
    if(ch == 'g'){
        return 0;
    }

    int n = str.length();
    string str1 = str;
    str += str1;

    bool isFound = false;
    int index = 0;
    int ans = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == ch && !isFound && i < n){
            isFound = true;
            index = i;
        }

        if(str[i] == 'g' && isFound){
            ans = max(ans, i - index);
            isFound = false;
        }
    }

    return ans;
}

int main(){
    // v();

    int t;
    cin >> t;

    while(t--){
        int n;
        char ch;
        cin >> n;
        cin >> ch;

        string str;
        cin >> str;

        cout << solve(str, ch) << "\n";

    }

    
    return 0;
}
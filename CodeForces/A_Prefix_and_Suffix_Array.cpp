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

string solve(vector<string> &arr, int n){
    unordered_map<int, string> m;

    for(int i = 0; i < arr.size(); i++){
        if(m.find(arr[i].length()) != m.end()){
            string str = m[arr[i].length()];
            string rev = str;
            reverse(rev.begin(), rev.end());
            if(!(arr[i] == str || arr[i] == rev)){
                return "NO";
            }
        }
        else{
            m[arr[i].length()] = arr[i];
        }
    }

    return "YES";
}

int main(){
    // v();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<string> arr(2 * n - 2);
        for(int i = 0; i < 2 * n - 2; i++){
            cin >> arr[i];
        }

        cout << solve(arr, n) << "\n";
    }


    
    return 0;
}
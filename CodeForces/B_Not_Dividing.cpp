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

void solve(vector<int> &arr){
    if(arr[0] == 1){
        arr[0] = 2;
    }

    int n = arr.size();

    for(int i = 1; i < n; i++){
        if(arr[i] == 1){
            arr[i]++;

            if(arr[i - 1] == 2){
                arr[i]++;
            }
        }
        if(arr[i] % arr[i - 1] == 0){
            arr[i]++;
        }
    }
}

int main(){
    // v();

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        solve(arr);

        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }

        cout << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;

// https://codeforces.com/contest/2003/problem/B


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n, 0);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(all(arr));

        cout << arr[n/2] << endl;
    }

    return 0;
}
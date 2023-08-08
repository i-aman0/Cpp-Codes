#include <bits/stdc++.h>
#include<iostream>

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
        int n, k;
        cin >> n >> k;

        vector<int> c(n);

        for(int i = 0; i < n; i++){
            cin >> c[i];
        }

        int s = 0, e = 0;
        int kStart = k;
        int kEnd = k;
        int i = 0, j = n - 1;

        if(c[0] == c[n - 1]){
            kStart = kStart/2;
            kEnd = k - kStart;
        }

        for(; i < n && s < kStart; i++){
            if(c[i] == c[0]){
                s++;
            }
        }

        for(; j >= 0 && e < kEnd; j--){
            if(c[j] == c[n - 1]){
                e++;
            }
        }

        if(i - 1 < j + 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    
    return 0;
}
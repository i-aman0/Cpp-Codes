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

    int n, h;
    cin >> n >> h;

    vector<int> heights(n);

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        heights[i] = temp;
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        if(heights[i] > h){
            ans += 2;
        }
        else{
            ans++;
        }
    }

    cout << ans;

    
    return 0;
}
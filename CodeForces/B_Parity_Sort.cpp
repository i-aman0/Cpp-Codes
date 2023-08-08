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

        vector<int> arr(n);
        vector<int> tempArr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            tempArr[i] = arr[i];
        }

        sort(tempArr.begin(), tempArr.end());

        bool flag = true;

        for(int i = 0; i < n; i++){
            if(arr[i] % 2 != tempArr[i] % 2){
                flag = false; 
                break;
            }
        }

        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    
    return 0;
}
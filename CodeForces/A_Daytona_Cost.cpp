#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        bool isPresent = false;

        for(int i = 0; i < n; i++){
            if(nums[i] == k){
                isPresent = true;
                break;
            }
        }

        if(isPresent){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl; 
        }
    }

    return 0;
}
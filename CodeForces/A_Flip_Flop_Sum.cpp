#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        vector<ll> nums(n);

        for(ll i = 0; i < n; i++){
            cin >> nums[i];
        }

        bool isNeg = false;
        bool isCons = false;

        for(auto num : nums){
            if(num == -1){
                isNeg = true;
                break;
            }
        }

        for(ll i = 1; i < n; i++){
            if(nums[i] == -1 && nums[i - 1] == -1){
                isCons = true;
                break;
            }
        }

        ll sum = 0;

        for(auto num : nums){
            sum += num;
        }

        if(isCons){
            sum += 4;
        }
        else if(isNeg){
            sum = sum;
        }
        else{
            sum -= 4;
        }

        cout << sum << endl;
    }

    return 0;
}
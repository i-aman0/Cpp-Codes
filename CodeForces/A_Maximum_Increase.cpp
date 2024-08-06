#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int maxLen = 1;
    int currLen = 1;

    for(int i = 1; i < n; i++){
        if(nums[i] > nums[i - 1]){
            currLen++;
        }
        else{
            maxLen = max(maxLen, currLen);
            currLen = 1;
        }
    }

    maxLen = max(maxLen, currLen);

    cout << maxLen << endl;

    return 0;
}